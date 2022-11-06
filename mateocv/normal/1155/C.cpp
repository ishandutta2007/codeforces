#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],p[m];
	fore(i,0,n)cin>>a[i];
	fore(j,0,m)cin>>p[j];
	if(n==1){
		cout<<"YES\n";
		cout<<a[0]<<" "<<1;
		return 0;
	}
	ll g=a[1]-a[0];
	fore(i,0,n-1){
		g=__gcd(g,a[i+1]-a[i]);
	}
	fore(i,0,m){
		if(g%p[i]==0){
			cout<<"YES\n";
			cout<<a[0]<<" "<<i+1;
			return 0;
		}
	}
	cout<<"NO\n";
	
	return 0;
}