#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<pair<int,int> >ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
main()
{
	cin>>n>>m;
	if(m<n-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(gcd(i,j)==1)
			{
				ans.push_back(make_pair(i,j));
				if(ans.size()==m)
				{
					puts("Possible");
					for(int i=0;i<m;i++)printf("%d %d\n",ans[i].first,ans[i].second);
					return 0;
				}
			}
		}
	}
	cout<<"Impossible"<<endl;
}