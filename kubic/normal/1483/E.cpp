#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
#define db double
mt19937 rand1(time(0));
int T,w1,w2;ll w,l,r,dp[N][N];char a[N];
int rdm(int l,int r) {return rand1()%(r-l+1)+l;}
bool qry(ll x)
{
	if(x>r) return 0;if(x>l) while(w<x) qry(l);
	printf("? %lld\n",x);fflush(stdout);scanf("%s",a);
	if(a[0]=='L') {w+=x;l=x;return 1;}w-=x;r=x-1;return 0;
}
void init()
{
	for(int i=0;i<=60;++i) dp[0][i]=1;
	for(int i=1;i<=60;++i) for(int j=1;j<=60;++j)
		dp[i][j]=dp[i-1][j-1]+dp[i-1][min(j+1,60)];
}
void slv()
{
	w=1;l=0;r=1e14;w1=55;w2=0;
	for(ll i=1;;i*=2) if(!qry(i)) break;
	while(dp[w1][w2]<=r-l) --w1,++w2;
	while(l<r) {--w1;if(qry(l+dp[w1][w2-1])) ++w2;else --w2;}
	printf("! %lld\n",l);fflush(stdout);
}
int main()
{
	scanf("%d",&T);init();
	while(T--) slv();return 0;
}