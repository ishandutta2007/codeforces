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
	ll n,k; cin>>n>>k;
	pair<ll,pair<ll,ll>> p[n];
	fore(i,0,n)cin>>p[i].fst>>p[i].snd.fst>>p[i].snd.snd;
	vector<ll> v[3];
	fore(i,0,n){
		if(p[i].snd.fst&&p[i].snd.snd)v[0].pb(p[i].fst);
		else if(p[i].snd.fst)v[1].pb(p[i].fst);
		else if(p[i].snd.snd)v[2].pb(p[i].fst);
	}
	sort(ALL(v[1])); sort(ALL(v[2]));
	reverse(ALL(v[1])); reverse(ALL(v[2]));
	while(SZ(v[1])&&SZ(v[2])){
		v[0].pb(v[1].back()+v[2].back());
		v[1].pop_back(); v[2].pop_back();
	}
	sort(ALL(v[0]));
	if(SZ(v[0])<k){
		cout<<-1;
	}else{
		ll res=0;
		fore(i,0,k)res+=v[0][i];
		cout<<res;
	}
	
	return 0;
}