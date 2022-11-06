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
	ll n,m; cin>>n>>m;
	vector<string> s(n);
	fore(i,0,n)cin>>s[i];
	vector<ll> a(m);
	fore(i,1,n){
		fore(j,1,m){
			if(s[i-1][j]=='X'&&s[i][j-1]=='X'){
				a[j]++;
			}
		}
	}
	vector<ll> sump={0};
	for(auto i:a)sump.pb(sump.back()+i);
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r;
		if(sump[r]-sump[l]>0)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}