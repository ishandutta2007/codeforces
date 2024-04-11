#include<cstdio>
#define int long long
const int N=1e5+5;
int n;
char a[N],b[N];
int cnt[2][2];
signed main()
{
	register int i;
	scanf("%lld",&n);
	scanf("%s%s",a+1,b+1);
	for(i=1;i<=n;i++)
		cnt[a[i]-'0'][b[i]-'0']++;
	printf("%lld\n",(cnt[0][0]+cnt[0][1])*(cnt[1][0]+cnt[1][1])-cnt[0][1]*cnt[1][1]);
}