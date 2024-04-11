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
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		ll cant[n+1][2];
		mset(cant,0);
		fore(i,0,n){
			fore(k,0,2)cant[i+1][k]=cant[i][k];
			cant[i+1][s[i]-'0']++;
		}
		while(q--){
			ll l,r; cin>>l>>r; l--;
			if(cant[l][s[l]-'0']-cant[0][s[l]-'0']>0||cant[n][s[r-1]-'0']-cant[r][s[r-1]-'0']>0){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
	
	return 0;
}