#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,m,p,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		if(p==-1)
		{
			if(m) m--;
			else ans++;
		}
		else m+=p;
	}
	printf("%d\n",ans);
	return 0;
}