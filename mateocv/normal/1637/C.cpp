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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		if(n==3){
			if(a[1]&1)cout<<"-1\n";
			else cout<<a[1]/2<<"\n";
			continue;
		}
		ll br=0;
		fore(i,1,n-1)br=(br||a[i]>=2);
		if(!br){
			cout<<"-1\n";
			continue;
		}
		ll res=0;
		fore(i,1,n-1)res+=(a[i]+1)/2;
		cout<<res<<"\n";
	}
	
	return 0;
}