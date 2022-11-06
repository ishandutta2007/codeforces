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

vector<pair<ll,ll>> v;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		v.clear();
		ll n,w; cin>>n>>w;
		fore(i,0,n){
			ll x; cin>>x;
			v.pb({x,i});
		}
		sort(ALL(v));
		while(SZ(v)&&v.back().fst>w)v.pop_back();
		ll br=0;
		for(auto i:v){
			if((w+1)/2<=i.fst&&i.fst<=w){
				cout<<"1\n"<<i.snd+1<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		reverse(ALL(v));
		ll sum=0;
		fore(i,0,SZ(v)){
			sum+=v[i].fst;
			if((w+1)/2<=sum&&sum<=w){
				cout<<i+1<<"\n";
				fore(j,0,i+1)cout<<v[j].snd+1<<" ";
				cout<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		cout<<"-1\n";
	}
	
	return 0;
}