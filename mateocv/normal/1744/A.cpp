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
		vector<ll> v(n);
		fore(i,0,n)cin>>v[i];
		string s; cin>>s;
		ll res=1;
		vector<ll> f(100,-1);
		fore(i,0,n){
			if(f[v[i]]==-1){
				f[v[i]]=s[i];
			}else{
				if(f[v[i]]!=s[i])res=0;
			}
		}
		cout<<(res?"YES":"NO")<<"\n";
	}
	
	return 0;
}