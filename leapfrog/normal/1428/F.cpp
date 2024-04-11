#include<cstdio>
int n,F[500005],nw=0;char ch[500005];long long rs=0,sm=0;
int main()
{
	scanf("%d%s",&n,ch+1);
	for(int i=1;i<=n;rs+=sm,i++) if(ch[i]&1) sm+=i-F[++nw];else for(;nw;nw--) F[nw]=i-nw;
	return printf("%lld\n",rs),0;
}