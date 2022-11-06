#include<cstdio>
const int N=1e5+5;
char s[N];
inline void solve()
{
	int cnt=0,n;
	scanf("%d%s",&n,s+1);
	for(int i=1;s[i]=='0'||s[i]=='1';i++)
		if(i>1&&s[i]==s[i-1])
			cnt++;
	printf("%d\n",(cnt+1)/2);
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