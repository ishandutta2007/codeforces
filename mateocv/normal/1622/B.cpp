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
		fore(i,0,n)cin>>a[i].fst,a[i].fst--,a[i].snd=i;
		string s; cin>>s;
		vector<pair<ll,ll>> v[2];
		fore(i,0,n)v[s[i]-'0'].pb(a[i]);
		fore(k,0,2)sort(ALL(v[k]));
		vector<ll> res(n);
		fore(i,0,SZ(v[0]))res[v[0][i].snd]=i;
		fore(i,0,SZ(v[1]))res[v[1][i].snd]=i+SZ(v[0]);
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}