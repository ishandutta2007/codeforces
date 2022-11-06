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
	ll n,m; cin>>n>>m;
	ll a[n],sum=0;
	fore(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ll res=0,van=0;
	fore(i,0,n){
		res++;
		if(van+1<=a[i])van++;
	}
	res+=a[n-1]-van;
	cout<<sum-res;
	
	return 0;
}