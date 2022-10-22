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
const int N=2e5+10;
int n,m,a[N],b[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y);} 
signed main(){
	n=read(),m=read();
	For(i,1,n)a[i]=read();
	For(i,1,m)b[i]=read();
	int x=0;For(i,2,n)x=gcd(x,abs(a[i]-a[i-1]));
	For(i,1,m)printf("%lld ",gcd(a[1]+b[i],x));
	return 0;
}