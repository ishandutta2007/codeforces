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
	ll n,q,k; cin>>n>>q>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	while(q--){
		ll l,r; cin>>l>>r; l--; r--;
		cout<<2ll*(k-(r-l+1))-(a[l]-1)-(k-a[r])<<"\n";
	}
	
	return 0;
}