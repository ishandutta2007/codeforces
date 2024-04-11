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

bool solve(ll n){
	if(n%11==0)return 1;
	fore(i,0,11){
		if(n-111*i>=0&&(n-111*i)%11==0)return 1;
	}
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(solve(n))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}