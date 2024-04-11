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
	ll a[n+1];
	a[0]=1e18;
	fore(i,0,n)cin>>a[i+1];
	set<ll> s={1000000000000000000};
	ll sump[n+1];
	sump[0]=a[0];
	fore(i,0,n)sump[i+1]=sump[i]+a[i+1];
	ll res=0;
	ll l=0,r=1;
	while(r<n+1){
		while(s.count(sump[r])){
			s.erase(sump[l]); l++;
		}
		s.insert(sump[r]);
		res+=SZ(s);
		//cout<<SZ(s)<<"\n";
		r++;
	}
	cout<<res-n;
	return 0;
}