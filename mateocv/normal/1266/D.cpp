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

ll s[100005];
int main(){FIN;
	ll n,m; cin>>n>>m;
	pair<pair<ll,ll>,ll> a[m];
	fore(i,0,m)cin>>a[i].fst.fst>>a[i].fst.snd>>a[i].snd,a[i].fst.fst--,a[i].fst.snd--;
	fore(i,0,m){
		s[a[i].fst.fst]+=a[i].snd;
		s[a[i].fst.snd]-=a[i].snd;
	}
	vector<pair<ll,ll>> v[2];
	fore(i,0,n){
		if(s[i]>0)v[0].pb({i,s[i]});
		else if(s[i]<0)v[1].pb({i,s[i]});
	} 
	vector<pair<pair<ll,ll>,ll>> res;
	while(SZ(v[0])||SZ(v[1])){
		ll mini=min(abs(v[0].back().snd),abs(v[1].back().snd));
		res.pb({{v[0].back().fst,v[1].back().fst},mini});
		v[0][SZ(v[0])-1].snd-=mini; v[1][SZ(v[1])-1].snd+=mini;
		if(v[0].back().snd==0)v[0].pop_back();
		if(v[1].back().snd==0)v[1].pop_back();
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res){
		cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd<<"\n";
	}	
	return 0;
}