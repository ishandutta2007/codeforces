#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*ll midd(ll x){
	for(int i=sqrt(n);i>0; i--){
		if(n%i==0)return i;
		return 1;
	}
}*/

int main(){FIN;
	ll n,sum=0; cin>>n;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ll mini=sum;
	for(int i=n-1;i>0;i--){
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				mini=min(mini,sum-a[i]+a[0]*(j-1)+a[i]/j);
			}
		}
	}
	cout<<mini;
	
	return 0;
}