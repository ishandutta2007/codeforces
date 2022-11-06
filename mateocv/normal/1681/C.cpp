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
		vector<pair<ll,ll>> a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		auto as=a;
		sort(ALL(as));
		ll br=0;
		fore(i,0,n-1){
			if(as[i].fst>as[i+1].fst)br++;
			if(as[i].snd>as[i+1].snd)br++;
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		vector<pair<ll,ll>> res;
		fore(i,0,n){
			fore(j,0,n){
				if(i!=j&&a[i]<a[j]){
					swap(a[i],a[j]);
					res.pb({i,j});
				}
			}
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}