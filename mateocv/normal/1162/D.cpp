#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	pair<ll,ll> a[m];
	fore(i,0,m){
		cin>>a[i].fst>>a[i].snd;
		a[i].fst--; a[i].snd--;
		if(a[i].fst>a[i].snd)swap(a[i].fst,a[i].snd);
	}
	sort(a,a+m);
	vector<ll> d;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			d.pb(i);
			if(n/i!=i&&n/i!=n)d.pb(n/i);
		}
	}
	vector<pair<ll,ll>> res;
	for(auto j:d){
		res.clear();
		fore(i,0,m){
			ll l=a[i].fst, r=a[i].snd;
			pair<ll,ll>p={(l+j)%n,(r+j)%n};
			if(p.fst>p.snd)swap(p.fst,p.snd);
			res.pb(p);
		}
		sort(ALL(res));
		ll tot=0;
		fore(i,0,m){
			if(a[i].fst==res[i].fst&&a[i].snd==res[i].snd)tot++;
		}
		if(tot==m){
			cout<<"Yes"; return 0;
		}
	}
	
	cout<<"No"; return 0;
	
	
	return 0;
}