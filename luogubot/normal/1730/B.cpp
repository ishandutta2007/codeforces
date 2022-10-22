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
int n,x[N],t[N],ans;
bool check(int lim){
	int L=0,R=2e8;
	For(i,1,n){
		if(t[i]>lim)return 0;
		int len=lim-t[i],l=x[i]-len,r=x[i]+len;
		L=max(l,L),R=min(r,R);
		if(L>R)return 0;
	}ans=L;
	return 1;
}
signed main(){
	int T=read();while(T--){
		n=read();
		For(i,1,n)x[i]=read()*2;For(i,1,n)t[i]=2*read();
		int l=0,r=1e10;
		while(l<=r){
			int m=l+r>>1;
			if(check(m))r=m-1;
			else l=m+1;
		}assert(check(r+1));
		if(ans&1)cout<<(ans/2)<<".5\n";
		else cout<<ans/2<<"\n";
	}
	return 0;
}