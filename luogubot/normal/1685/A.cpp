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
const int N=1e5+10;
int n,a[N],b[N]; 
bool ok(int x,int y,int z){return x<y&&y>z||x>y&&y<z;}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read();sort(a+1,a+1+n);
		if((n&1)){puts("NO");continue;}
		For(i,1,n/2)b[i*2-1]=a[i];For(i,1,n/2)b[i*2]=a[i+n/2];
		int fl=1;For(i,2,n-1)fl&=ok(b[i-1],b[i],b[i+1]);
		fl&=ok(b[n],b[1],b[n])&ok(b[n-1],b[n],b[1]);
		if(!fl)puts("NO");else {puts("YES");For(i,1,n)printf("%lld ",b[i]);puts("");}
	}
	return 0;
}