#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n,m;
vector<int> oa,ob;
signed main()
{
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(__gcd(i,j)==1)
			{
				sum++;
				oa.push_back(i);
				ob.push_back(j);
			}
			if(sum==m) break;
		}
		if(sum==m) break;
	}	
	if(sum<m||m<n-1)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	for(int i=0;i<(int)oa.size();i++) printf("%d %d\n",oa[i],ob[i]);
	return 0;
}