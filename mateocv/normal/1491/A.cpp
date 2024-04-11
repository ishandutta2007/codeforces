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
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll c=0;
	fore(i,0,n)c+=(a[i]==1);
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll pos; cin>>pos; pos--;
			if(a[pos]==1)c--;
			else c++;
			a[pos]=1-a[pos];
		}else{
			ll k; cin>>k; k--;
			if(k>=c)cout<<"0\n";
			else cout<<"1\n";
		}
	}
	
	return 0;
}