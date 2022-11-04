#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9,inf=0x3f3f3f3f3f3f3f3f;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct edge {int to,nxt;} e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;} 

int Q,lst,cnt=1,w[N],f[N][29],s[N][29];

void add(int u,int v,int x) {
	//cout<<"A "<<u<<" "<<v<<" "<<x<<endl;
	if(w[u]<x) per(h,20,0) if(w[f[u][h]]<x) u=f[u][h];
	f[v][0]=u=(w[u]>=x?u:f[u][0]);
	s[v][0]=w[u];
	rep(h,1,20)
		f[v][h]=f[f[v][h-1]][h-1],
		s[v][h]=(f[v][h]?min(inf,s[f[v][h-1]][h-1]+s[v][h-1]):inf);
}
int query(int u,int d,int ret=0) {
	//cout<<"Q "<<u<<" "<<d<<endl;
	//rep(h,0,20) cout<<(s[u][h]==inf?-1:s[u][h])<<" ";
	per(h,20,0) if(s[u][h]<=d) d-=s[u][h], u=f[u][h], ret+=(1<<h);
	return ret+1;
}

signed main() {
	Q=read();
	w[0]=inf; memset(s[1],0x3f,sizeof(s[1])), memset(s[0],0x3f,sizeof(s[0]));
	while(Q--) {
		int opt=read(), p=read(), q=read();
		int r=p^lst, x=q^lst;
		if(opt==1) w[++cnt]=x, add(r,cnt,x);
		else printf("%lld\n",lst=(x>=w[r]?query(r,x-w[r]):0));
	}
	return 0;
}