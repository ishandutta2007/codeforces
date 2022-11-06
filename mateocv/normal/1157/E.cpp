#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

map<ll,ll> m;

int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)m[b[i]]++;
	ll c[n];
	fore(i,0,n){
		auto it=m.lower_bound(n-a[i]);
		if(it==m.end()){
			it=m.begin();
		}
		c[i]=((*it).fst+a[i])%n;
		m[(*it).fst]--;
		if(m[(*it).fst]==0)m.erase((*it).fst);
	}
//	for(auto i:m)cout<<i.fst<<" "<<i.snd<<"\n";
	fore(i,0,n)cout<<c[i]<<" ";
	return 0;
}