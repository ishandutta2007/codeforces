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
int n,a[N],m,L[N],R[N],fa[N];
vector<int> g[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void work(int l,int r){
	if(l>r)swap(l,r);
	for(int i=get(l);i<=r;i=get(i+1)){
		a[i]=0,fa[i]=i+1;for(auto v:g[i])if(!a[v])work(v,i);
	}
}
signed main(){
	int T=read();while(T--){
		n=read(),m=read();g[0].clear();
		For(i,1,n)a[i]=read(),fa[i]=i,g[i].clear();
		For(i,1,n)a[i]+=a[i-1]-read();
		For(i,1,m){
			L[i]=read(),R[i]=read();
			g[L[i]-1].push_back(R[i]),g[R[i]].push_back(L[i]-1);
		}fa[n+1]=n+1,fa[0]=0;
		For(i,0,n)if(!a[i])fa[i]=fa[i+1];For(i,1,m){
			if(a[L[i]-1]==a[R[i]]&&!a[R[i]])work(L[i]-1,R[i]);
		}int fl=1;For(i,0,n)fl&=(!a[i]);puts(fl?"YES":"NO");
	}
	return 0;
}