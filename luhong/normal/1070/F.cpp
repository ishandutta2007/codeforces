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

int n;
int s[400005],a[400005];
int A,B,C,Ans;
int b[400005],t1;
int c[400005],t2;
priority_queue<int> pq;

int main(){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d%d",s+i,a+i);
		if(s[i]==11) ++A, Ans+=a[i];
		if(s[i]==10) ++B, b[B]=a[i], Ans+=a[i];
		if(s[i]==01) ++C, c[C]=a[i], Ans+=a[i];
		if(s[i]==00) pq.push(a[i]);
	}
	if(B>C){
		sort(b+1,b+B+1);
		F(i,1,B-C) Ans-=b[i], pq.push(b[i]);
	}
	else{
		sort(c+1,c+C+1);
		F(i,1,C-B) Ans-=c[i], pq.push(c[i]);
	}
	F(i,1,A) if(!pq.empty()) Ans+=pq.top(), pq.pop();
	printf("%d",Ans);
	return 0;
}