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
	
	ll b,k; cin>>b>>k;
	ll sum=0,llega;
	fore(i,0,k-1){
		cin>>llega;
		sum+=(b*llega);
		sum%=2;
	}
	
	cin>>llega;
	sum+=llega;
	sum%=2;
	
	if(sum){cout<<"odd";
	}else{cout<<"even";
	}
	
	return 0;
}