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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i]>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		ll res=1;
		if(!(n&1)){
			res=(a[n/2]-a[n/2-1]+1)*(b[n/2]-b[n/2-1]+1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}