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

const int MAXN=400005;

vector<pair<ll,ll>> v;

ll ub[MAXN];

bool vis[MAXN];

ll mexl,mexr;

void swp(ll pos){
	swap(v[pos].fst,v[pos].snd);
}

ll l[2],r[2];

void upd(ll pos, ll di, ll val){
	if(di==0){
		l[pos]=max(l[pos],val);
	}else{
		r[pos]=min(r[pos],val);
	}
	vis[val]=1;
	while(vis[mexl]==1)mexl++;
	while(vis[mexr]==1)mexr--;
}

int main(){FIN;
	ll n; cin>>n;
	v.resize(n);
	fore(i,0,n)cin>>v[i].fst>>v[i].snd;
	mset(ub,-1);
	fore(i,0,n){
		ub[v[i].fst]=i;
		ub[v[i].snd]=i;
	}
	l[0]=0;
	l[1]=0;
	r[0]=2*n+1;
	r[1]=2*n+1;
	mexl=1,mexr=2*n;
	ll res=0;
	while(mexl<=2*n){
		ll u=ub[mexl];
		ll va=0,tot=0;
		if((v[u].fst^v[u].snd^mexl)==mexr){
			if(v[u].fst!=mexl)swp(u);
			upd(0,0,mexl);
			upd(1,1,mexr);
		}else{
			tot++;
			if(v[u].fst!=mexl)va++,swp(u);
			upd(0,0,v[u].fst);
			upd(1,1,v[u].snd);
			while(mexl<max(l[0],l[1])||mexr>min(r[0],r[1])){
				if(mexl<l[1]){
					u=ub[mexl];
					tot++;
					if(v[u].fst!=mexl)va++,swp(u);
					upd(0,0,v[u].fst);
					upd(1,1,v[u].snd);
					continue;
				}
				if(mexl<l[0]){
					u=ub[mexl];
					tot++;
					if(v[u].snd!=mexl)va++,swp(u);
					upd(0,1,v[u].fst);
					upd(1,0,v[u].snd);
					continue;
				}
				if(mexr>r[1]){
					u=ub[mexr];
					tot++;
					if(v[u].fst!=mexr)va++,swp(u);
					upd(0,1,v[u].fst);
					upd(1,0,v[u].snd);
					continue;
				}
				if(mexr>r[0]){
					u=ub[mexr];
					tot++;
					if(v[u].snd!=mexr)va++,swp(u);
					upd(0,0,v[u].fst);
					upd(1,1,v[u].snd);
					continue;
				}
			}
			res+=min(va,tot-va);
		}
	}
	sort(ALL(v));
	ll br=0;
	fore(i,0,SZ(v)-1){
		if(v[i].snd<=v[i+1].snd)br++;
	}
	if(br)cout<<"-1\n";
	else cout<<res<<"\n";
	
	return 0;
}