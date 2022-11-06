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
		vector<pair<ll,ll>> v(3);
		fore(i,0,3)cin>>v[i].snd>>v[i].fst;
		sort(ALL(v));
		if(v[1].fst==v[2].fst)cout<<abs(v[1].snd-v[2].snd)<<"\n";
		else cout<<"0\n";
	}
	
	return 0;
}