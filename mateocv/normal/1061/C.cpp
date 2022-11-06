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

ll MOD=1ll*1e9+7;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll cant[1000005];
	memset(cant,0,sizeof cant);
	fore(i,0,n){
		for(int j=1; j*j<a[i];j++){
			if(a[i]%j==0){
				cant[a[i]/j-1]+=cant[a[i]/j-2];
				cant[a[i]/j-1]%=MOD;
			}
		}
		for(int j=sqrt(a[i]); j>1;j--){
			if(a[i]%j==0){
				cant[j-1]+=cant[j-2];
				cant[j-1]%=MOD;
			}
		}
		cant[0]++;
	}
	ll sum;
	fore(i,0,n){
		sum+=cant[i];
		sum%=MOD;
	}
	cout<<sum;
	
	
	return 0;
}