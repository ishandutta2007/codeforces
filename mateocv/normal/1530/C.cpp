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

vector<ll> a,b;

bool can(ll m){
	vector<ll> aa;
	for(auto i:a)aa.pb(i);
	fore(i,0,m)aa.pb(100);
	vector<ll> bb;
	fore(i,0,m)bb.pb(0);
	for(auto i:b)bb.pb(i);
	ll sa=0;
	for(auto i:aa)sa+=i;
	fore(i,0,SZ(aa)/4)sa-=aa[i];
	ll sb=0;
	for(auto i:bb)sb+=i;
	fore(i,0,SZ(bb)/4)sb-=bb[i];
	return sa>=sb;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		b.clear();
		a.resize(n);
		b.resize(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b));
		ll l=0,r=4*n;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}