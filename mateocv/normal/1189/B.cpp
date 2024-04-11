#include <bits/stdc++.h>
#define pb push_back
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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	vector<ll> res;
	for(int i=0;i<n;i+=2){
		res.pb(a[i]);
	}
	for(int i=n-1-(n%2);i>0;i-=2){
		res.pb(a[i]);
	}
	ll tot=0;
	fore(i,1,n-1){
		if(res[i]<res[i-1]+res[i+1])tot++;
	}
	if(res[0]<res[1]+res[n-1])tot++;
	if(res[n-1]<res[0]+res[n-2])tot++;
	if(tot==n){
		cout<<"YES\n";
		fore(i,0,n)cout<<res[i]<<" ";
	}else{
		cout<<"NO";
	}
	return 0;
}