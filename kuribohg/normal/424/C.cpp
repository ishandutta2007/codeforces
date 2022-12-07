#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,p[MAXN],s[MAXN],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),ans^=p[i];
	for(int i=1;i<n;i++) s[i]=s[i-1]^i;
	for(int i=1;i<=n;i++)
	{
		int t=n/i;
		if(t%2==1) ans^=s[i-1];
		ans^=s[n%i];
	}
	printf("%d\n",ans);
	return 0;
}