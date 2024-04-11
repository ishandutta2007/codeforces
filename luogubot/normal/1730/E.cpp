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
const int N=5e5+10,V=1e6+10;
int n,a[N];ll ans;
vector<int> D[V];
int mx[N],mn[N],t[V];
int c[V];
#define lowbit(x) (x&-x)
void add(int u,int v){for(int i=u;i;i-=lowbit(i))c[i]+=v;}
int ask(int u,int s=0){for(int i=u;i<V;i+=lowbit(i))s+=c[i];return s;}
void solve(int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	mx[mid]=mn[mid]=a[mid];
	Rof(i,mid-1,l)mx[i]=max(mx[i+1],a[i]),mn[i]=min(mn[i+1],a[i]);
	mx[mid+1]=mn[mid+1]=a[mid+1];
	For(i,mid+2,r)mx[i]=max(mx[i-1],a[i]),mn[i]=min(mn[i-1],a[i]);
	int R=mid+1;
	Rof(L,mid,l){
		int MX=mx[L],MN=mn[L];
		while(R<=r&&mx[R]<=MX)t[mn[R]]++,add(mn[R],1),R++;
		for(auto d:D[MX])if(MN>=d){ans+=t[d];if(MN==d)ans+=ask(d+1);}else break;
	}For(i,mid+1,R-1)add(mn[i],-1),t[mn[i]]--;
	int L=mid;
	For(R,mid+1,r){
		int MX=mx[R],MN=mn[R];
		while(L>=l&&mx[L]<MX)t[mn[L]]++,add(mn[L],1),L--;
		for(auto d:D[MX])if(MN>=d){ans+=t[d];if(MN==d)ans+=ask(d+1);}else break;
	}For(i,L+1,mid)add(mn[i],-1),t[mn[i]]--;
	solve(l,mid),solve(mid+1,r);
}
signed main(){
	n=1e6;For(i,1,n)For(j,1,n/i)D[i*j].push_back(i);
	int T=read();while(T--){For(i,1,n=read())a[i]=read();ans=n,solve(1,n);cout<<ans<<"\n";}
	return 0;
}