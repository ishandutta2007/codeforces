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
const int N=1e3+10,p=998244353;
int head[N],to[N],nxt[N],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
int n,m,a[N],b[N],c[N],deg[N];
int f[N][N],yc[N][N];
queue<int> q;
void topo(){
	For(i,1,n){
		f[0][i]=a[i];
		if(f[0][i]>=p)f[0][i]%=p,yc[0][i]=1;
	} 
	For(i,1,n)if(!deg[i])q.push(i);
	int ed=0;
	while(!q.empty()){
		int u=q.front();q.pop(),ed=u;
		go(u){
			int v=to[i];
			For(i,1,n){
				f[i][v]+=f[i-1][u],yc[i][v]|=yc[i-1][u];
				if(f[i][v]>=p)f[i][v]%=p,yc[i][v]=1;
			}
			if(!--deg[v])q.push(v);
		}
	}
	int ans=0,add=-1,fl=0; 
	For(i,0,n){
		fl|=(ans+f[i][ed]>=p);
		fl|=yc[i][ed];
		(ans+=f[i][ed])%=p;
		if(ans>0||fl)(ans+=p-1)%=p,add=i;
	}cout<<((ans+add)%p+1)%p<<endl;
}
signed main(){
	int T=read();while(T--){
		n=read(),m=read(),cnt=0;
		For(i,1,n)a[i]=b[i]=read(),head[i]=deg[i]=0;
		For(i,0,n)For(j,0,n)f[i][j]=yc[i][j]=0;
		For(i,1,m){
			int x=read(),y=read();
			deg[y]++,add(x,y);
		}topo();
	}
	return 0;
}