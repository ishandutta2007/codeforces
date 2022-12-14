#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int mod=400;
int n,q,m[333][111111],x,lastans,tp,li,ri,ki,l,r,k,bl,br,res;
deque<int> d[333];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		d[i/mod].push_back(x);
		m[i/mod][x]++; 
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&tp,&li,&ri);
		l=(li+lastans-1)%n+1;
		r=(ri+lastans-1)%n+1;
		if (l>r) swap(l,r);
		--l;
		bl=l/mod;br=r/mod;
		if (tp==1)
		{
			if (bl==br) 
			{
				x=d[bl][r%mod-1];
				d[bl].erase(d[bl].begin()+r%mod-1);
				d[bl].insert(d[bl].begin()+l%mod,x);
			}
			else
			{
				for (int i=bl;i<br;i++)
				{
					int old=d[i].back();
					m[i][old]--;
					d[i].pop_back();
					d[i+1].push_front(old);
					m[i+1][old]++; 
				}
				x=d[br][r%mod];
				m[br][x]--;
				d[br].erase(d[br].begin()+r%mod);
				m[bl][x]++;
				d[bl].insert(d[bl].begin()+l%mod,x);  
			}
		}
		else
		{
			scanf("%d",&ki);
			k=(ki+lastans-1)%n+1;
			res=0;
			if (bl==br)
			{
				for (int i=l%mod;i<r%mod;i++) res=res+(d[bl][i]==k);
			}
			else
			{
				for (int i=bl+1;i<br;i++) res+=m[i][k];
				for (int i=l%mod;i<mod;i++) res+=(d[bl][i]==k);
				for (int i=0;i<r%mod;i++) res+=(d[br][i]==k);
			}
			cout<<res<<endl;
			lastans=res;
		}
	}
	return 0;
}