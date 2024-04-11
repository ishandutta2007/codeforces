#include<cstdio>
#include<iostream>
#define int long long
using std::min;
const int N=1e6+5;
int n,x,y,cnt;
char s[N];
signed main()
{
	register int i;
	scanf("%lld%lld%lld",&n,&x,&y);
	scanf("%s",s+1);s[n+1]='1';
	for(i=2;i<=n+1;i++)
		if(s[i]=='1'&&s[i-1]=='0')
			cnt++;
	if(!cnt)
		return puts("0"),0;
	printf("%lld\n",min(x,y)*(cnt-1)+y);
	return 0;
}