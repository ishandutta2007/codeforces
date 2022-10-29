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
		for(int i=1;i<=n;i++) cin>>a[i];
		
		if(n%2==1)
		{
			cout<<-1<<endl;
			continue;
		}
		
		vector< pair<int,int> >ans;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1) sum+=a[i];
			else sum-=a[i];
		}
		int las=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				if(sum<0 && a[i]>0) 
				{
					ans.emplace_back(las+1,i-1);
					ans.emplace_back(i,i);
					las=i;
					
					sum+=2;
				}
				else if(sum>0 && a[i]<0)
				{
					ans.emplace_back(las+1,i-1);
					ans.emplace_back(i,i);
					las=i;
					
					sum-=2;
				}
			}
		}
		if(las!=n) ans.emplace_back(las+1,n);
		cout<<ans.size()<<endl;
		for(auto [u,v]:ans) cout<<u<<' '<<v<<endl;
		
	}
	
	return 0;
}