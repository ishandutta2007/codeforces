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

int main(){FIN;
	ll n; cin>>n;
	vector<ll> v[2];
	ll lle;
	fore(i,0,n){
		cin>>lle;
		v[lle%2].pb(lle);
	}
	ll m=min(SZ(v[0]),SZ(v[1]));
	sort(ALL(v[0])); sort(ALL(v[1]));
	fore(i,0,m){
		v[0].pop_back(); v[1].pop_back();
	}
	ll sum=0;ll maxi=0;
	fore(k,0,2){
		fore(i,0,SZ(v[k])){
			sum+=v[k][i];
			maxi=v[k][i];
		}	
	}
	cout<<sum-maxi;
	
	
	
	return 0;
}