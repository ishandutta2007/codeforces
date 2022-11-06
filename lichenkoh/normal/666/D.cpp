#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF = 1ULL<<58ULL;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
pair<ll,ll> sol[8];
ll x[4],y[4];
ll final;
void solve(ll r) {
	if (r) {
		for (ll j=0;j<4;j++) swap(x[j],y[j]);
	}
	bool has=false;
	set<ll> sy;
	for (ll i=0;i<4;i++) sy.insert(y[i]);
	vector<ll> vy;
	for (auto &w: sy) vy.PB(w);
	ll d=abs(vy[1]-vy[0]);
	map<ll,ll> my;
	for (ll i=0;i<2;i++) {
		my[vy[i]]=i;
	}
	vector<pair<ll,ll> > b[2];
	for (ll i=0;i<4;i++) {
		ll idx=my[y[i]];
		b[idx].PB(MP(x[i],i));
	}
	for (ll idx=0;idx<2;idx++) {
		sort(b[idx].begin(),b[idx].end());
	}
	ll imin=0; ll imax=1e9;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		set<ll> sx;
		for (ll idx=0;idx<2;idx++) {
			sx.insert(b[idx][0].first+imid);
			sx.insert(b[idx][0].first-imid);
			sx.insert(b[idx][1].first+imid-d);
			sx.insert(b[idx][1].first-imid-d);
		}
		ll best=INF;
		for (auto &w:sx) {
			ll ans=0;
			for (ll idx=0;idx<2;idx++) {
				chkmax(ans, abs(w-b[idx][0].first));
				chkmax(ans, abs(w+d-b[idx][1].first));
			}
			chkmin(best,ans);
			if (ans<final) {
				final=ans;
				has=true;
				for (ll idx=0;idx<2;idx++) {
					sol[b[idx][0].second]=MP(w,vy[idx]);
					sol[b[idx][1].second]=MP(w+d,vy[idx]);
				}
			}
		}
		if (best>imid) {
			imin=imid+1;
		}
		else imax=imid;
	}
	if (r) {
		for (ll j=0;j<4;j++) swap(x[j],y[j]);
		if (has) {
			for (ll j=0;j<4;j++) swap(sol[j].first,sol[j].second);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	ll t; cin>>t;
	for (ll ii=0;ii<t;ii++) {
		for (ll j=0;j<4;j++) {
			cin>>x[j]>>y[j];
		}
		map<ll,ll> hx,hy;
		for (ll j=0;j<4;j++) {
			hx[x[j]]++;hy[y[j]]++;
		}
		bool xg=true;
		for (auto &w:hx) {
			if (w.second!=2) xg=false;
		}
		bool yg=true;
		for (auto &w:hy) {
			if (w.second!=2) yg=false;
		}
		final=INF;
		//printf("xg yg: %d %d\n",xg,yg);
		if (xg) {
			solve(1);
		}
		if (yg) {
			solve(0);
		}
		set<ll> sd;
		sd.insert(0);
		for (ll i=0;i<4;i++) {
			for (ll j=i+1;j<4;j++) {
				sd.insert(abs(x[i]-x[j]));
				sd.insert(abs(y[i]-y[j]));
			}
		}
		set<ll> sx, sy;
		for (ll i=0;i<4;i++) {
			for (auto &w: sd) {
				sx.insert(x[i]+w);
				sy.insert(y[i]+w);
				sx.insert(x[i]-w);
				sy.insert(y[i]-w);
			}
		}
		for (ll i=0;i<4;i++) {
			sx.erase(x[i]); sy.erase(y[i]);
		}
		vector<ll> vx,vy;
		for (ll i=0;i<4;i++) {
			vx.PB(x[i]); vy.PB(y[i]);
		}
		for (auto &w: sx) vx.PB(w);
		for (auto &w: sy) vy.PB(w);
		ll xn=vx.size(),yn=vy.size();
		for (ll a=0;a<4;a++) {
			for (ll b=a+1;b<xn;b++) {
				for (ll c=0;c<yn;c++) {
					for (ll d=c+1;d<yn;d++) {
						if (abs(vx[a]-vx[b]) != abs(vy[c]-vy[d])) continue;
						pair<ll,ll> pt[4];
						pt[0]=MP(vx[a],vy[c]);
						pt[1]=MP(vx[a],vy[d]);
						pt[2]=MP(vx[b],vy[c]);
						pt[3]=MP(vx[b],vy[d]);
  					ll myints[] = {0,1,2,3};
  					do {
  						ll ans=0;
  					  for (ll k=0;k<4;k++) {
  					  	pair<ll,ll> p=pt[myints[k]];
  					  	pair<ll,ll> q=MP(x[k],y[k]);
  					  	ll best=INF;
  					  	if (p.first==q.first) {
  					  		best=abs(p.second-q.second);
  					  	}
  					  	else if (p.second==q.second) {
  					  		best=abs(p.first-q.first);
  					  	}
  					  	chkmax(ans,best);
  					  	if (ans>=final) break;
  					  }
  					  if (ans<final) {
  					  	final=ans;
  					  	for (ll i=0;i<4;i++) {
  					  		sol[i]=pt[myints[i]];
  					  	}
  					  }
  					} while ( std::next_permutation(myints,myints+4) );
					}
				}
			}
		}
		for (ll a=0;a<xn;a++) {
			for (ll b=a+1;b<xn;b++) {
				for (ll c=0;c<4;c++) {
					for (ll d=c+1;d<yn;d++) {
						if (abs(vx[a]-vx[b]) != abs(vy[c]-vy[d])) continue;
						pair<ll,ll> pt[4];
						pt[0]=MP(vx[a],vy[c]);
						pt[1]=MP(vx[a],vy[d]);
						pt[2]=MP(vx[b],vy[c]);
						pt[3]=MP(vx[b],vy[d]);
  					ll myints[] = {0,1,2,3};
  					do {
  						ll ans=0;
  					  for (ll k=0;k<4;k++) {
  					  	pair<ll,ll> p=pt[myints[k]];
  					  	pair<ll,ll> q=MP(x[k],y[k]);
  					  	ll best=INF;
  					  	if (p.first==q.first) {
  					  		best=abs(p.second-q.second);
  					  	}
  					  	else if (p.second==q.second) {
  					  		best=abs(p.first-q.first);
  					  	}
  					  	chkmax(ans,best);
  					  	if (ans>=final) break;
  					  }
  					  if (ans<final) {
  					  	final=ans;
  					  	for (ll i=0;i<4;i++) {
  					  		sol[i]=pt[myints[i]];
  					  	}
  					  }
  					} while ( std::next_permutation(myints,myints+4) );
					}
				}
			}
		}
		if (final >=INF) {
			cout<<-1<<endl;
		}
		else {
			cout<<final<<endl;
			for (ll i=0;i<4;i++) {
				cout<<sol[i].first<<" "<<sol[i].second<<endl;
			}
		}
	}
}