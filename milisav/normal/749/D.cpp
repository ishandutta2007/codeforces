#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct st
{
	int l;
	vector<int> vr;
};
vector<st> a;
int ai[200005];
int bi[200005];
int ci[200005];
int di[200005];
int n;
int al,bl;
int m;
int binary(int ind,int val)
{
	
	int l0=0;
	int r0=a[ind].vr.size()-1;
	int m0;
	//cout<<"ale  "<<val<<" "<<r0<<endl;
	m0=(l0+r0)/2+1;
	while(l0<r0)
	{
		//cout<<l0<<" "<<m0<<" "<<r0<<" "<<a[ind].vr[m0]<<" "<<val<<endl;
		if(a[ind].vr[m0]>val) l0=m0;
		else r0=m0-1;
		m0=(l0+r0)/2+1;
	}
	return a[ind].vr[l0];
}
int main()
{
	scanf("%d",&n);
	st p;
	for(int i=0;i<=n;i++) ci[i]=-1;
	for(int i=0;i<n;i++) scanf("%d %d",&ai[i],&bi[i]);
	for(int i=n-1;i>=0;i--)
	{
		
		if(ci[ai[i]]==-1)
		{
			ci[ai[i]]=a.size();
			p.l=ai[i];
			a.push_back(p);
			a[ci[ai[i]]].vr.push_back(bi[i]);
		}
		else
		{
			a[ci[ai[i]]].vr.push_back(bi[i]);
		}
	}
	for(int i=0;i<=n;i++) ci[i]=1;
	int q,k;
	int fin;
	int kon;
	m=a.size();
	scanf("%d",&q);
	while(q>0)
	{
		al=-1;
		bl=-1;
		scanf("%d",&k);
		for(int i=0;i<k;i++) scanf("%d",&di[i]);
		for(int i=0;i<k;i++) ci[di[i]]=0;
		for(int i=0;i<m;i++)
		{
			if(ci[a[i].l]==1)
			{
				if(al==-1) al=i;
				else
				{
					bl=i;
					i=m;
				}
			}
		}
		if(al==-1) printf("0 0\n");
		else
		{
			if(bl==-1) fin=0;
			else fin=a[bl].vr[0];
			kon=binary(al,fin);
			printf("%d %d\n",a[al].l,kon);
		}
		for(int i=0;i<k;i++) ci[di[i]]=1;
		q--;
	}
	return 0;
}