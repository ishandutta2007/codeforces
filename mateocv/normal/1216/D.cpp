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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll g=0;
	ll mini=a[0];
	ll maxi=a[0];
	ll sum=0;
	fore(i,0,n)mini=min(mini,a[i]);
	fore(i,0,n){
		g=__gcd(g,a[i]-mini);
		maxi=max(maxi,a[i]);
		sum+=a[i];
	}
	cout<<(maxi*n-sum)/g<<" "<<g<<"\n";
	
	
	return 0;
}