#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,1,n+1){
			if(k>i*(i+1)/2)continue;
			string res;
			fore(j,0,n)res+='a';
			res[i]='b';
			res[i-(i*(i+1)/2-k)-1]='b';
			reverse(ALL(res));
			cout<<res<<"\n";
			break;
		}
	}
	
	return 0;
}