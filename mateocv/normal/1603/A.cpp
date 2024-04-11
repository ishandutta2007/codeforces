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
		ll pos=SZ(a)-1;
		while(SZ(a)&&pos>=0){
			if(a[pos]%(pos+2)!=0){
				vector<ll> b;
				while(SZ(a)>pos){
					b.pb(a.back());
					a.pop_back();
				}
				b.pop_back();
				while(SZ(b)){
					a.pb(b.back());
					b.pop_back();
				}
				pos=SZ(a)-1;
			}else pos--;
		}
		if(SZ(a)==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}