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
	ll a[n],maxi=0;
	fore(i,0,n){
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}
	ll maxl=0,va=0;
	fore(i,0,n){
		if(a[i]==maxi){va++;
		}else{va=0;
		}
		maxl=max(maxl,va);
	}
	cout<<maxl;
	
	return 0;
}