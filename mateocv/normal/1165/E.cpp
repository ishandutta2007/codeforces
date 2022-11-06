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

const ll MOD=998244353;

int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n){
		a[i]*=(i+1)*(n-i);
	}
	sort(a,a+n);
	sort(b,b+n);
	reverse(b,b+n);
	fore(i,0,n)a[i]%=MOD;
	fore(i,0,n)b[i]%=MOD;
	ll res=0;
	fore(i,0,n){
		res+=(a[i]*b[i])%MOD;
		res%=MOD;
	}
	cout<<res;
	return 0;
}