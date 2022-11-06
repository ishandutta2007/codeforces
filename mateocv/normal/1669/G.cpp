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
		ll n,m; cin>>n>>m;
		vector<string> v(n);
		fore(i,0,n)cin>>v[i];
		fore(j,0,m){
			for(ll i=n-1;i>=0;i--){
				if(v[i][j]=='*'){
					ll pos=i;
					while(pos+1<n&&v[pos+1][j]=='.'){
						v[pos][j]='.';
						v[pos+1][j]='*';
						pos++;
					}
				}
			}
		}
		for(auto i:v)cout<<i<<"\n";
	}
	
	return 0;
}