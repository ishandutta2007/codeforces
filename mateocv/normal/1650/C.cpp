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
		ll n,m; cin>>n>>m;
		vector<pair<pair<ll,ll>,ll>> v(m);
		fore(i,0,m)cin>>v[i].fst.snd>>v[i].fst.fst,v[i].snd=i;
		sort(ALL(v));
		while(SZ(v)>2*n)v.pop_back();
		ll s=0;
		for(auto i:v)s+=i.fst.fst;
		fore(i,0,SZ(v))swap(v[i].fst.fst,v[i].fst.snd);
		sort(ALL(v));
		cout<<s<<"\n";
		fore(i,0,n)cout<<v[i].snd+1<<" "<<v[2*n-1-i].snd+1<<"\n";
	}
	
	return 0;
}