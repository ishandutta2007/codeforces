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
	ll n,d; cin>>n>>d;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	reverse(ALL(a));
	ll l=0,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		ll c=0;
		fore(i,0,m){
			c+=(d+a[i])/a[i];
		}
		if(c<=n)l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	
	return 0;
}