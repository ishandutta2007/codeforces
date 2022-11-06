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

vector<ll> v;
ll a[200005];
vector<pair<ll,ll>> res;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		v.clear();
		fore(i,1,n+1)a[i]=i;
		ll va=n;
		v.pb(va);
		while(va>2){
			fore(i,1,n+1){
				if(i*i>=va){
					va=i;
					v.pb(va);
					break;
				}
			}
		}
		assert(va==2);
		res.clear();
		fore(i,2,n){
			ll br=0;
			for(auto j:v){
				if(i==j)br++;
			}
			if(br)continue;
			res.pb({i,i+1});
			a[i]=(a[i]+a[i+1]-1)/a[i+1];
		}
		reverse(ALL(v));
		while(SZ(v)>1){
			ll b=v.back();
			v.pop_back();
			ll bb=v.back();
			res.pb({b,bb});
			a[b]=(a[b]+a[bb]-1)/a[bb];
			res.pb({b,bb});
			a[b]=(a[b]+a[bb]-1)/a[bb];
		}
		ll cant=0;
		fore(i,0,n){
			cant+=(a[i+1]>=2);
		}
		assert(cant==1);
		assert(SZ(res)<=n+5);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	}
	
	return 0;
}