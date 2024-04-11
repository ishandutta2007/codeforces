#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

int n;
int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int Tcase; cin>>Tcase;
	while(Tcase--)
	{
		cin>>n;
		int m=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			m+= (a[i]!=0);
		}
		
		if(m%2==1)
		{
			cout<<-1<<endl;
			continue;
		}
		
		vector< pair<int,int> >ans;
		int k1=0,k2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				if(k1==0) k1=i;
				else if(k2==0)
				{
					k2=i;
					int sig= (k1%2)==(k2%2) ? 1:-1;
					int sum= a[k1]+sig*a[k2];
					if(sum!=0)
					{
						ans.emplace_back(k1,k1);
						ans.emplace_back(k1+1,k2);
					}
					else ans.emplace_back(k1,k2);
					k1=k2=0;
				}
			}
			else
			{
				if(k1==0) ans.emplace_back(i,i);
			}
		}
		
		cout<<ans.size()<<endl;
		for(auto [u,v]:ans) cout<<u<<' '<<v<<endl;
		
	}
	
	return 0;
}