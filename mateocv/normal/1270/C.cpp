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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll s=0,x=0;
		fore(i,0,n)s+=a[i],x^=a[i];
		ll l=(1ll<<50);
		if(s%2)l++;
		cout<<"3\n"<<l<<" "<<(x^l)-(s+l)/2<<" "<<(x^l)-(s+l)/2<<"\n";
	}
	
	return 0;
}