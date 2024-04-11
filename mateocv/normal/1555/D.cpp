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
	string s; cin>>s;
	vector<ll> sump[6];
	string abc="abc";
	ll va=0;
	do{
		sump[va]={0};
		fore(i,0,n){
			sump[va].pb(sump[va].back()+(s[i]!=abc[i%3]));
		}
		va++;
	}while(next_permutation(ALL(abc)));
	while(m--){
		ll l,r; cin>>l>>r; l--;
		ll res=n;
		fore(i,0,6)res=min(res,sump[i][r]-sump[i][l]);
		cout<<res<<"\n";
	}
	
	
	return 0;
}