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
int n,q,a[N],v[N];
bool check(int m){
	For(i,1,n)v[i]=0;
	For(i,1,n)if(a[i]<=q)v[i]=1,m--;
	if(m<=0)return 1;
	Rof(i,n,1){
		if(!v[i])v[i]=1,m--;
		if(!m)break;
	}int x=q;For(i,1,n)if(v[i]){
		if(x<=0)return 0;
		if(a[i]>x)x--;
	}return 1;
}
signed main(){
	int T=read();while(T--){
		n=read(),q=read();For(i,1,n)a[i]=read();
		int l=0,r=n;while(l<=r){
			int m=l+r>>1;
			if(check(m))l=m+1;
			else r=m-1;
		}check(l-1);For(i,1,n)putchar(v[i]+'0');puts("");
	}
	return 0;
}