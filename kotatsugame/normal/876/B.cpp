#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int a,n,k,m;
vector<int>c[1<<17];
main()
{
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		c[a%m].push_back(a);
		if(c[a%m].size()>=k)
		{
			cout<<"Yes"<<endl;
			for(int j=0;j<c[a%m].size();j++)printf("%d%c",c[a%m][j],j==c[a%m].size()-1?10:32);
			return 0;
		}
	}
	cout<<"No"<<endl;
}