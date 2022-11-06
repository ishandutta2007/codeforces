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
	string s[n],t[m];
	fore(i,0,n)cin>>s[i];
	fore(i,0,m)cin>>t[i];
	ll q; cin>>q;
	while(q--){
		ll y; cin>>y;
		y--;
		cout<<s[y%n]<<t[y%m]<<"\n";
	}
	return 0;
}