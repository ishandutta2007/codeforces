#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100010;
int n,p,ans;
bool used[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&p);
		used[p]=true;
	}
	for(int i=1;i<=n;i++)
		if(!used[i]) {ans=i;break;}
	printf("%d\n",ans);
	return 0;
}