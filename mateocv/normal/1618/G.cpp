#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> vp;

vector<ll> sump;

const int MAXN=500005;
int pa[MAXN],sz[MAXN],c[MAXN],r[MAXN];
ll resp=0;
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y])swap(x,y);
		resp-=sump[r[x]]-sump[r[x]-c[x]];
		resp-=sump[r[y]]-sump[r[y]-c[y]];
		sz[y]+=sz[x];
		pa[x]=y;
		c[y]+=c[x];
		r[y]=max(r[x],r[y]);
		resp+=sump[r[y]]-sump[r[y]-c[y]];
	}
}

vector<ll> ev[MAXN];

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vector<ll> a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	vector<pair<ll,ll>> qs(q);
	fore(i,0,q)cin>>qs[i].fst,qs[i].snd=i;
	sort(ALL(qs));
	fore(i,0,n)vp.pb({a[i],1});
	fore(i,0,m)vp.pb({b[i],0});
	sort(ALL(vp));
	//for(auto i:vp)cout<<i.fst<<" "<<i.snd<<"\n";
	sump.pb(0);
	for(auto i:vp)sump.pb(sump.back()+i.fst);
	//for(auto i:sump)cout<<i<<" ";
	//cout<<"\n";
	fore(i,0,SZ(vp)-1){
		ll l=0,r=q-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(vp[i+1].fst-vp[i].fst<=qs[m].fst)r=m-1;
			else l=m+1;
		}
		//cout<<i<<" "<<l<<"\n";
		ev[l].pb(i);
	}
	fore(i,0,SZ(vp)){
		pa[i]=i;
		sz[i]=1;
		c[i]=vp[i].snd;
		r[i]=i+1;
		if(c[i])resp+=vp[i].fst;
	}
	vector<ll> res(q);
	fore(i,0,q){
		for(auto j:ev[i])join(j,j+1);
		res[qs[i].snd]=resp;
	}
	for(auto i:res)cout<<i<<"\n";
	
	return 0;
}