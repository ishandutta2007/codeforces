#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	int a=0,b=0,N;
	scanf("%d",&n);N=n;
	F(i,2,n){
		if(i*i>n) break;
		if(n%i) continue;
		if(!a) a=i;
		else {b=i; break;}
		while(n%i==0) n/=i;
	} if(n>1){
		if(!a) a=n;
		else if(!b) b=n;
	}
	if(!a||!b) return puts("NO"),0;
	puts("YES");
	n=N;
	F(i,1,b) if((n-1-i*a)%b==0) return printf("2\n%d %d\n%d %d\n",i,n/a,(n-1-i*a)/b,n/b),0;
	return 0;
}