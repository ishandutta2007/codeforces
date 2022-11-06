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

ll s;

bool can(ll m){
	ll n=SZ(v);
	ll va=m;
	fore(i,0,n){
		if(va>=v[i].snd){
			va+=v[i].fst;
		}
	}
	return va>=s;
}

int main(){FIN;
	ll n; cin>>n;
	v.resize(n);
	fore(i,0,n)cin>>v[i].snd>>v[i].fst;
	sort(ALL(v));
	fore(i,0,n)swap(v[i].fst,v[i].snd);
	s=0;
	for(auto i:v)s+=i.fst;
	ll l=0,r=s;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<s+l<<"\n";
	
	return 0;
}