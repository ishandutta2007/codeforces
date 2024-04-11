#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
#define ff first
#define ss second
#define mp make_pair
#define pi pair<int,int>
using namespace std;
const int N=100005;
const int inf=1e9+7;
typedef long long ll;
typedef long double lb;
inline void read(int &x){x=0; char ch=getchar();while(ch<'0') ch=getchar();while(ch>='0'){x=x*10+ch-48; ch=getchar();}}
//------------------------------------------head---------------------------------------------------//
unsigned int f[2][N];
char s[N];
const unsigned int pp=25;
const int Q=2;
int main()
{
	int n; read(n); scanf("%s",s+1); f[0][0]=1; register int cur=0,nxt,up,j,fk;
	rep(i,1,n)
	{
		nxt=cur^1; up=min(i,n-i+1);fk=(n-i)&1;
		for(j=2-fk;j<=up;j+=Q)
		{
			if(s[i]=='?') f[nxt][j]=f[cur][j+1]+pp*f[cur][j-1];	
			else f[nxt][j]=f[cur][j-1];
		} if(s[i]=='?')f[nxt][0]=f[cur][1];else f[nxt][0]=0;
		cur=nxt;
	}
	ll rp=f[cur][0]; printf("%I64d\n",rp);
	return 0;
}