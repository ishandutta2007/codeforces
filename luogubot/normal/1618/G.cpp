#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define ll long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=4e5+10;
int n,m,q;
#define pi pair<int,int>
#define fi first
#define se second
pi c[N],a[N],d[N];
int fa[N],sz[N];
ll s[N],ans,res[N];
inline int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
inline void merge(int x,int y){
	x=get(x),y=get(y);if(x==y)return;
	ans-=s[x]-s[x-sz[x]],ans-=s[y]-s[y-sz[y]];
	fa[x]=y,sz[y]+=sz[x],ans+=s[y]-s[y-sz[y]];
}
signed main(){
	n=read(),m=read(),q=read();
	For(i,1,n)a[i].fi=read(),a[i].se=1;For(i,n+1,n+m)a[i].fi=read(),a[i].se=0;sort(a+1,a+1+n+m);
	For(i,1,n+m)s[i]=s[i-1]+a[i].fi;
	For(i,1,q)c[i].fi=read(),c[i].se=i;sort(c+1,c+1+q);
	For(i,1,n+m-1)d[i]=pi(a[i+1].fi-a[i].fi,i);sort(d+1,d+n+m);
	For(i,1,n+m+1){fa[i]=i;if(a[i].se)sz[i]=1,ans+=a[i].fi;}
	for(int i=1,j=1;i<=q;i++){
		while(j<n+m&&d[j].fi<=c[i].fi)merge(d[j].se,d[j].se+1),j++;
		res[c[i].se]=ans;
	}For(i,1,q)printf("%lld\n",res[i]);
	return 0;
}//fdasfas