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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	vector<pair<ll,ll>> v;
	set<ll> s;
	fore(i,0,n)s.insert(i+1);
	fore(i,0,n){
		if(a[i]!=0){
			s.erase(a[i]);
		}else{
			v.pb({i,-1});
		}
	}
	fore(i,0,SZ(v)){
		if(s.count(v[i].fst+1)){
			v[i].snd=v[i].fst+1;
			s.erase(v[i].fst+1);
		}
	}
	fore(i,0,SZ(v)){
		if(v[i].snd==-1){
			ll p=*s.begin();
			v[i].snd=p;
			s.erase(p);
		}
	}
	map<ll,ll> m;
	fore(i,0,SZ(v)){
		m[v[i].fst]=v[(i+1)%SZ(v)].snd;
	}
	fore(i,0,n){
		if(a[i]!=0)cout<<a[i]<<" ";
		else cout<<m[i]<<" ";
	}
	
	return 0;
}