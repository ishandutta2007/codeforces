//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int P=998244353;int dp[105][10][10][2][2][4][4][4][4],n,A,B;char nc[105];
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline int dfs(int x,int jwa,int jwb,int lma,int lmb,int st1,int st2,int st3,int st4)//lim = rs<=n
{
	int &r=dp[x][jwa][jwb][lma][lmb][st1][st2][st3][st4];if(~r) return r;else r=0;
	if(x==0) return r=lma&&lmb&&!jwa&&!jwb&&(st1==3||st2==3||st3==3||st4==3);
	for(int i=0;i<10;i++)
	{
		int va=jwa+i*A,bta=va%10,vb=jwb+i*B,btb=vb%10;
		char la=bta==nc[x]?lma:(bta<nc[x]),lb=btb==nc[x]?lmb:(btb<nc[x]);
		char s1=st1|((bta==A)<<1|(btb==B)),s2=st2|((bta==A*2)<<1|(btb==B*2));
		char s3=st3|((bta==A*3)<<1|(btb==B*3)),s4=st4|((bta==A*4)<<1|(btb==B*4));
		r=(r+dfs(x-1,va/10,vb/10,la,lb,s1,s2,s3,s4))%P;
	}
	return r;
}
inline int solve(int a,int b) {return A=a,B=b,memset(dp,-1,sizeof(dp)),dfs(n,0,0,1,1,0,0,0,0);}
int main()
{
	scanf("%s",nc+1),n=strlen(nc+1);for(int i=1;i<=n;i++) nc[i]^=48;
	int rs=0;for(int i=1;i<=n;i++) rs=(rs*10ll+nc[i])%P;
	for(int i=1;i<=9;i++) for(int j=i+1;j<=9;j++) if(gcd(i,j)==1) rs=(rs+2ll*solve(i,j))%P;
	return printf("%d\n",rs),0;
}