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
	ll l,r;
	ll u[n+1];
	fore(i,0,n)u[a[i]]=i;
	l=u[n]; r=u[n];
	for(ll i=n-1;i>=1;i--){
		if(u[i]==l-1){
			l--;
		}else if(u[i]==r+1){
			r++;
		}else{
			cout<<"NO"; return 0;
		}
	}
	cout<<"YES";
	return 0;
}