#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,a[N];
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read();int fl=1;
		int g=1;For(i,1,n){
			g=g/__gcd(g,i+1)*(i+1);
			if(g>1e9)break;
			fl&=(a[i]%g!=0);
		}puts(fl?"YES":"NO");
	}
	return 0;
}