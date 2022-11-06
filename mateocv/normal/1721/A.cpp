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
		vector<ll> c(26);
		fore(i,0,4){
			char x; cin>>x;
			c[x-'a']++;
		}
		ll res=4;
		fore(i,0,26){
			ll va=0;
			fore(j,0,26){
				if(i!=j)va+=(c[j]+1)/2;
			}
			res=min(res,va);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}