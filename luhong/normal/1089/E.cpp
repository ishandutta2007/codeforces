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
	scanf("%d",&n);
	if(n<=50){
		printf("a1 ");
		int x=1, y=1;
		while(n>2){
			if(x&1) {if(y==7) ++x; else ++y;}
			else {if(y==1) ++x; else --y;}
			printf("%c%d ",'a'+x-1,y);
			--n;
		}
		printf("%c%d h8\n",'a'+x-1,8);
	}
	else if(n!=63){
		printf("a1 ");
		int x=1, y=1;
		while(n>2){
			if(x==8){
				--y;
				if(y==0) y=7;
			}
			else if(x==7&&y==2) ++x;
			else if(x==7){
				--y;
				if(y==0) y=7;
			}
			else if(x&1) {if(y==8) ++x; else ++y;}
			else {if(y==1) ++x; else --y;}
			printf("%c%d ",'a'+x-1,y);
			--n;
		}
		if(x<=6){
			if(y==8) printf("%c%d ",'a'+x,y);
			else printf("%c%d ",'h',y);
		}
		else if(x==7){
			printf("h%d ",y);
		}
		else if(x==8){
			printf("h%d ",y-1==0?7:y-1);
		}
		printf("h8\n");
	}
	else{
		printf("a1 ");
		int x=1, y=1;
		while(x!=7||y!=6){
			if(x&1) {if(y==8) ++x; else ++y;}
			else {if(y==1) ++x; else --y;}
			printf("%c%d ",'a'+x-1,y);
		}
		printf("g8 g7 h7 h1 h2 h3 h4 h5 h6 h8\n");
	}
	return 0;
}