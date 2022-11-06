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
		pair<ll,ll> a[n];
		fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
		sort(a,a+n);
		vector<ll> v={1};
		fore(i,1,n){
			if(a[i].snd>=a[i-1].snd)v[SZ(v)-1]++;
			else{
				v.pb(1);
			}
		}
		ll maxi=0;
		for(auto i:v)maxi=max(maxi,i);
		cout<<n-maxi<<"\n";
	}
	
	return 0;
}