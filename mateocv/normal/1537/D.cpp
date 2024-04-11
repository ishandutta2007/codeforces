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
		ll res=-1;
		if(n&1){
			res=0;
		}else{
			if(__builtin_popcount(n)==1){
				ll c=0;
				while(n%2==0){
					c++;
					n/=2;
				}
				if(c&1)res=0;
				else res=1;
			}else{
				res=1;
			}
		}
		if(res)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	
	return 0;
}