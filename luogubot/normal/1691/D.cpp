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
const int N=2e5+10,LG=18;
int n,a[N],s[N],L[N],R[N],stk[N],tp;
int f[LG][N],g[LG][N];
void build(){
	For(i,0,n)f[0][i]=g[0][i]=s[i];
	For(j,1,LG-1)For(i,0,n-(1<<j)+1)
		f[j][i]=max(f[j-1][i],f[j-1][i+(1<<j-1)]),
		g[j][i]=min(g[j-1][i],g[j-1][i+(1<<j-1)]);
}
int get1(int l,int r){
	int p=__lg(r-l+1);return max(f[p][l],f[p][r-(1<<p)+1]);
}
int get2(int l,int r){
	int p=__lg(r-l+1);return min(g[p][l],g[p][r-(1<<p)+1]);
}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read(),s[i]=s[i-1]+a[i];
//		For(i,1,n)printf("%d ",s[i]);puts("");
		build();
		tp=0;For(i,1,n){
			while(tp&&a[stk[tp]]<a[i])R[stk[tp--]]=i-1;
			stk[++tp]=i;
		}while(tp)R[stk[tp--]]=n;
		Rof(i,n,1){
			while(tp&&a[stk[tp]]<a[i])L[stk[tp--]]=i+1;
			stk[++tp]=i;
		}while(tp)L[stk[tp--]]=1;int fl=1;
		For(i,1,n){
			int l=L[i],r=R[i];
//			printf("%d [%d,%d] (%d)-(%d)\n",i,l,r,get1(i,r),get2(l-1,i-1));
			int val=get1(i,r)-get2(l-1,i-1);
			if(val>a[i])fl=0;
		}puts(fl?"YES":"NO");
	}
	return 0;
}