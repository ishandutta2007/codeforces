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

int main(){FIN;
	ll n; cin>>n;
	pair<ll,ll> a[n]; ll c[n];
	fore(i,0,n)cin>>a[i].fst>>a[i].snd>>c[i],c[i]--;
	vector<pair<pair<ll,ll>,ll>> v;
	fore(i,0,n){
		v.pb({{a[i].fst,1},i});
		v.pb({{a[i].snd+1,-1},i});
	}
	sort(ALL(v));
	set<ll> st[2];
	set<pair<ll,ll>> r[2];
	ll res=0;
	fore(i,0,SZ(v)){
		if(v[i].fst.snd==1){
			st[c[v[i].snd]].insert(v[i].snd);
			r[c[v[i].snd]].insert({a[v[i].snd].snd,v[i].snd});
		}else{
			if(st[c[v[i].snd]].count(v[i].snd)){
				if(SZ(r[c[v[i].snd]^1])){
					auto it=r[c[v[i].snd]^1].begin();
					res++;
					st[c[v[i].snd]^1].erase(it->snd);
					r[c[v[i].snd]^1].erase({a[it->snd].snd,it->snd});
				}
				st[c[v[i].snd]].erase(v[i].snd);
				r[c[v[i].snd]].erase({a[v[i].snd].snd,v[i].snd});
			}
		}
	}
	cout<<n-res<<"\n";
	return 0;
}