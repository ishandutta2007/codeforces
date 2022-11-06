#include<cstdio>
const int N=105;
int n,ans;
char s[N];
signed main()
{
	int i,j;
	scanf("%d\n",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='F'&&s[i-1]=='S')
			ans++;
		else if(s[i]=='S'&&s[i-1]=='F')
			ans--;
	puts(ans>0?"YES":"NO");
	return 0;
}