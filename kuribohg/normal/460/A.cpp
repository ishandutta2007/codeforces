#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,k,ans;
int main()
{
	scanf("%d%d",&n,&k);
	while(n>0)
	{
		n--;
		ans++;
		if(ans%k==0) n++;
	}
	printf("%d\n",ans);
	return 0;
}