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
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,k; cin>>n>>m>>k;
	if((2*m*n)%k==0){
		cout<<"YES"<<"\n";
//		int a=2*m*n/k;
		ll g=__gcd(2*n,k);
		if(g>1){cout<<"0 0\n"<<2*n/g<<" 0\n0 "<<m*g/k;}
		else{cout<<"0 0\n"<<n<<" 0\n0 "<<2*m/k;
		}
	}else{
		cout<<"NO";
	}
	
	return 0;
}