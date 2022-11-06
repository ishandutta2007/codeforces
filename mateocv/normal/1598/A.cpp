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
		string a,b; cin>>a>>b;
		ll br=0;
		fore(i,0,n){
			if(a[i]=='1'&&b[i]=='1')br++;
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}