#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,cnt[N][26];char a[N];
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;++i) for(int j=0;j<26;++j)
		cnt[i][j]=cnt[i-1][j]+(a[i]-'a'==j);
	scanf("%d",&m);
	for(int i=1,l,r,t;i<=m;++i)
	{
		scanf("%d %d",&l,&r);t=0;
		for(int j=0;j<26;++j) t+=(cnt[r][j]-cnt[l-1][j]>0);
		if(l<r && t<=2 && a[l]==a[r]) puts("No");else puts("Yes");
	}return 0;
}