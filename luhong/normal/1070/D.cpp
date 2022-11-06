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
set<int,int> st;

LL n,q,m,k;
LL a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

LL Ans;

int main(){
	scanf("%lld%lld",&n,&k);
	F(i,1,n) scanf("%lld",a+i);
	F(i,1,n){
		LL x=b[i]/k+(b[i]%k!=0);
		Ans+=x;
		a[i]-=(x*k)-b[i];
		if(a[i]>0){
			Ans+=a[i]/k;
			b[i+1]=a[i]%k;
		}
	} Ans+=b[n+1]/k+(b[n+1]%k!=0);
	printf("%lld\n",Ans);
	return 0;
}