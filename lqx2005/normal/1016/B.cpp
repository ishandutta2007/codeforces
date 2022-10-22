#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,m,q;
int cnt[maxn+5];
char s[maxn+5],t[maxn+5];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)
	{
		if(i+m-1>n) continue;
		bool flag=1;
		for(int j=i;j<=i+m-1;j++)
		{
			if(s[j]!=t[j-i+1])
			{
				flag=0;
				break;
			}
		}
		if(flag) cnt[i]++;
	}
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	int l,r;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		r=(r-m+1);
		if(l>r) printf("0\n");
		else printf("%d\n",cnt[r]-cnt[l-1]); 
	}
	return 0;
}