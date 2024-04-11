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
#define pi pair<int,int>
#define fi first
#define se second
pi b[N];int tp;
int n,k,a[N];
int solve(){
	tp=0;for(int i=k-1,j;i>=1;i=j){
		int now=0,sum=0;j=i;
		while(j>=1&&sum<=0)sum+=a[j],now=max(now,-sum),j--;
		if(sum>0)b[++tp]=pi(now,sum);
	}
//	For(i,1,tp)printf(">=%d +=%d\n",b[i].fi,b[i].se);
	int now=a[k],j=1;For(i,k+1,n){
		while(j<=tp&&now>=b[j].fi)now+=b[j++].se;
		now+=a[i];if(now<0)return 0;
	}return 1;
}
signed main(){
	int T=read();while(T--){
		n=read(),k=read();For(i,1,n)a[i]=read();
		int fl=solve();reverse(a+1,a+1+n),k=n-k+1;fl|=solve();
		puts(fl?"YES":"NO");
	}
	return 0;
}