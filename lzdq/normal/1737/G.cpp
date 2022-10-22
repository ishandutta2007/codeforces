#include<cstdio>
#include<algorithm>
#include<cstring>
#include<chrono>
#include<random>
#include<cassert>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,Inf=0x3fffffff;
const ll INF=1ll<<60;
int n,n0,n1,d,q;
ll a[MAXN],a0[MAXN],a1[MAXN];
char s[MAXN];
struct Ques{
	int k,m,id;
}qs[MAXN];
bool operator <(Ques a,Ques b){
	return a.k<b.k;
}
namespace Treap{
	mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
#define lc ch[u][0]
#define rc ch[u][1]
	int rt,ch[MAXN][2],siz[MAXN];
	ll tag[MAXN],val[MAXN];
	inline void pushup(int u){
		siz[u]=siz[lc]+siz[rc]+1;
	}
	inline void add(int u,ll v){
		if(u){
			tag[u]+=v;
			val[u]+=v;
		}
	}
	inline void pushdwn(int u){
		if(tag[u]){
			add(lc,tag[u]);
			add(rc,tag[u]);
			tag[u]=0;
		}
	}
	int Build(int l,int r){
		if(l>r) return 0;
		int u=l+r>>1;
		lc=Build(l,u-1);
		rc=Build(u+1,r);
		siz[u]=r-l+1;
		val[u]=a1[u];
		return u;
	}
	void SplitS(int u,int &x,int &y,int k){
		if(!u){
			x=y=0;
			return ;
		}
		pushdwn(u);
		if(siz[lc]<k){
			x=u;
			SplitS(rc,ch[x][1],y,k-siz[lc]-1);
		}else{
			y=u;
			SplitS(lc,x,ch[y][0],k);
		}
		pushup(u);
		return ;
	}
	void SplitT(int u,int &x,int &y,ll lx,int s){
		if(!u){
			x=y=0;
			return ;
		}
		pushdwn(u);
		int rk=s+siz[lc]+1;
		//printf("lx %lld x %lld rk %d\n",lx,val[u],rk);
		if(val[u]-lx-rk+2<=d){
			x=u;
			SplitT(rc,ch[x][1],y,lx,rk);
		}else{
			y=u;
			SplitT(lc,x,ch[y][0],lx,s);
		}
		pushup(u);
		return ;
	}
	void SplitV(int u,int &x,int &y,ll v){
		if(!u){
			x=y=0;
			return ;
		}
		pushdwn(u);
		if(val[u]<v){
			x=u;
			SplitV(rc,ch[x][1],y,v);
		}else{
			y=u;
			SplitV(lc,x,ch[y][0],v);
		}
		pushup(u);
		return ;
	}
	int Merge(int x,int y){
		if(!x||!y) return x+y;
		if(rnd()%(siz[x]+siz[y])<siz[x]){
			pushdwn(x);
			ch[x][1]=Merge(ch[x][1],y);
			pushup(x);
			return x;
		}
		pushdwn(y);
		ch[y][0]=Merge(x,ch[y][0]);
		pushup(y);
		return y;
	}
	ll GetKth(int u,int k){
		if(k>siz[u]) return INF;
		pushdwn(u);
		if(k==siz[lc]+1) return val[u];
		if(k<=siz[lc]) return GetKth(lc,k);
		return GetKth(rc,k-siz[lc]-1);
	}
	void Print(int u){
		if(!u) return ;
		pushdwn(u);
		Print(lc);
		printf("%lld,",val[u]);
		Print(rc);
	}
	void Put(int u){
		Print(u);
		puts("");
	}
#undef lc
#undef rc
}
using namespace Treap;
ll ans[MAXN];
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&d,&q);
	for(int i=1; i<=n; i++)
		scanf("%lld",a+i);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++)
		if(s[i]=='0') n0++,a0[n0]=a[i]-n0;
		else a1[++n1]=a[i]-n0;
	for(int i=1; i<=q; i++){
		scanf("%d%d",&qs[i].k,&qs[i].m);
		qs[i].id=i;
	}
	sort(qs+1,qs+q+1);
	n=n1;
	rt=Build(1,n);
	int qq=1,tm=0;
	while(qq<=q){
		if(qs[qq].k==tm){
			int l=1,r=n+1;
			while(l<r){
				int mid=l+r>>1;
				ll x=GetKth(rt,mid);
				int rk=mid+(lower_bound(a0+1,a0+n0+1,x)-a0-1);
				if(rk>=qs[qq].m) r=mid;
				else l=mid+1;
			}
			ll x=GetKth(rt,l);
			int cnt=(lower_bound(a0+1,a0+n0+1,x)-a0-1),rk=l+cnt;
			if(rk==qs[qq].m) ans[qs[qq].id]=x+cnt;
			else rk=cnt-(rk-qs[qq].m-1),ans[qs[qq].id]=a0[rk]+rk;
			qq++;
			continue;
		}
		int dt=qs[qq].k-tm;
		ll lx=GetKth(rt,1);
		int a,b,c;
		SplitT(rt,a,c,lx,0);
		n1=siz[a];
		//printf("n1 %d\n",n1);
		if(n1<n){
			ll rx=GetKth(c,1);
			ll dis=d+n1-1;
			ll k=(rx-lx+dis-1)/dis;
			assert(k>=2);
			dt=min(1ll*dt,(k-1)*n1);
			SplitV(a,a,b,rx-(k-1)*dis);
			if(b) dt=min(1ll*dt,siz[a]+(k-2)*n1);
			//puts("a"); Put(a);
			//puts("b"); Put(b);
			a=Merge(a,b);
		}
		//printf("dt %d\n",dt);
		assert(dt);
		ll dis=d+n1-1;
		add(a,dis*(dt/n1));
		int w=dt%n1;
		SplitS(a,a,b,w);
		add(a,dis);
		a=Merge(b,a);
		rt=Merge(a,c);
		tm+=dt;
		//printf("tm %d\n",tm);
		//Put(rt);
	}
	for(int i=1; i<=q; i++)
		printf("%lld\n",ans[i]);
	return 0;
}