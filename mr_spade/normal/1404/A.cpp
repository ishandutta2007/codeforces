#include<cstdio>
#include<cstring>
const int N=1e6+5;
int n,k,a,b,c;
char s[N];
int t[N];
inline void solve()
{
	register int i;
	scanf("%d%d%s",&n,&k,s);
	memset(t,-1,sizeof(int)*k);
	for(i=0;i<n;i++)
		if(s[i]!='?')
		{
			if(~t[i%k]&&t[i%k]!=s[i]-'0')
				return puts("NO"),void();
			t[i%k]=s[i]-'0';
		}
	a=b=c=0;
	for(i=0;i<k;i++)
		switch(t[i])
		{
			case -1:a++;break;
			case 0:b++;break;
			case 1:c++;break;
		}
	if(a+b>=c&&a+c>=b)
		puts("YES");
	else
		puts("NO");
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}