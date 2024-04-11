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

bool isp(vector<ll> s){
	auto sr=s;
	reverse(ALL(sr));
	return s==sr;
}

vector<ll> filt(vector<ll> v, ll val){
	vector<ll> res;
	for(auto i:v){
		if(i!=val)res.pb(i);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		if(isp(a)){
			cout<<"YES\n";
			continue;
		}
		auto ar=a;
		reverse(ALL(ar));
		pair<ll,ll> d={-1,-1};
		fore(i,0,n){
			if(a[i]!=ar[i]){
				d={a[i],ar[i]};
				break;
			}
		}
		if(isp(filt(a,d.fst))||isp(filt(a,d.snd)))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}