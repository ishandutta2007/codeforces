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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		deque<ll> d;
		fore(i,0,n)d.pb(a[i]);
		vector<ll> res;
		while(SZ(d)){
			res.pb(d.front());
			d.pop_front();
			if(SZ(d)==0)break;
			res.pb(d.back());
			d.pop_back();
		}
		reverse(ALL(res));
		for(auto i:res)cout<<i<<" "; cout<<"\n";
	}
	
	return 0;
}