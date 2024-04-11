#include<cstdio>
#include<bitset>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2005;
int t,n;
int p[N<<1];
bitset<N*3> dp[N<<1][2],tmp[N<<1][2];
int stk[N<<1],top;
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,2*n) cin>>p[i];
		fr(i,1,2*n+1) {
			dp[i][0].reset();
			dp[i][1].reset();
			tmp[i][0].reset();
			tmp[i][1].reset();
		}
		p[2*n+1]=2*n+1;
		fr(i,1,2*n+1) {
			while(top&&p[stk[top]]<p[i]) {
				tmp[i][1]|=tmp[stk[top]][1];
				tmp[i][0]|=tmp[stk[top]][0];
				--top;
			}
			dp[i][0]|=tmp[i][1];
			dp[i][1]|=tmp[i][0]<<i;
			if(i==1) dp[i][0][2*n]=1;
			tmp[i][0]|=dp[i][0]>>i;
			tmp[i][1]|=dp[i][1];
			stk[++top]=i;
		}
		cout<<(dp[2*n+1][0][3*n]||dp[2*n+1][1][3*n]?"YES":"NO")<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}