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

ll a[10004];
vector<pair<pair<ll,ll>,ll>> res;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		res.clear();
		ll sum=0;
		fore(i,0,n){
			sum+=a[i];
		}
		if(sum%n!=0){
			cout<<"-1\n";
			continue;
		}
		fore(i,1,n){
			res.pb({{0,i},(i+1-a[i]%(i+1))%(i+1)});
			res.pb({{i,0},(a[i]+i)/(i+1)});
		}
		fore(i,1,n){
			res.pb({{0,i},sum/n});
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd<<"\n";
	}
	
	return 0;
}