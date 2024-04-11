#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long 
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10;
int n,a[N],b[N],stk[N],tp;
signed main(){
	int T=read();while(T--){
		int n=read(),L=read(),R=read(),fl=0,tp=0;
		For(u,1,n){
			if(fl)break;
			int len=2*(n-u);
			if(L>len)L-=len,R-=len;
			else{
				For(v,u+1,n){
					if(L>2){L-=2,R-=2;continue;}
					if(L==2){stk[++tp]=v,L--,R-=2;continue;}
					if(L==1&&R>=1){
						stk[++tp]=u,stk[++tp]=v;
						R-=2;if(R<0)tp--,R++;
					}
				}if(R>=1)For(uu,u+1,n)if(R>=1)For(vv,uu+1,n)if(R>=1){
					stk[++tp]=uu,stk[++tp]=vv;
					R-=2;if(R<0)tp--,R++;
				}break;
			}
		}if(R>=1)stk[++tp]=1,R--;assert(!R);
		For(i,1,tp)printf("%lld ",stk[i]);puts("");
	}
	return 0;
}