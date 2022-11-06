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

int main(){FIN;
	ll n; cin>>n;
	ll a[n],sum[2];
	sum[0]=0;
	sum[1]=0;
	fore(i,0,n){
		cin>>a[i];
		sum[i%2]+=a[i];
	}
	ll res=0;
	for(ll i=n-1;i>=0;i--){
		if(i==n-1){
			sum[(n-1)%2]-=a[n-1];
		}else{
			sum[i%2]-=a[i];
			sum[i%2]+=a[i+1];
		}
		if(sum[0]==sum[1])res++;
	}
	cout<<res;
	return 0;
}