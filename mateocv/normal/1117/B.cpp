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
	ll n,m,k; cin>>n>>m>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll res=0,van=0;
/*	while(m--){
		if(van<k){
			res+=a[n-1];
			van++;
		}else{
			res+=a[n-2];
			van=0;
		}
	}*/
	ll tan=k*a[n-1]+a[n-2];
	res+=m/(k+1);
	res*=tan;
	res+=a[n-1]*(m%(k+1));
	
	cout<<res;
	return 0;
}