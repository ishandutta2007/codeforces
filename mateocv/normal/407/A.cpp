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

ll hip(ll x){
	fore(i,1,x){
		fore(j,1,x){
			if(i*i+j*j==x*x){return i;
			}
		}	
	}
	return 0;
}

int main(){FIN;
	ll a,b; cin>>a>>b;
	ll g=__gcd(a,b);
	if(hip(g)){
		ll i=hip(g);
		ll l=1.*sqrt(1.*g*g-1.*i*i)+1e-9;
		if(i*a/g==l*b/g){
			cout<<"YES\n0 "<<i*a/g<<"\n";
			cout<<l*a/g<<" 0\n";
			cout<<i*b/g<<" "<<2*l*b/g<<"\n";
		}else{
			cout<<"YES\n0 "<<i*a/g<<"\n";
			cout<<l*a/g<<" 0\n";
			cout<<l*a/g+i*b/g<<" "<<l*b/g<<"\n";
		}
	}else{cout<<"NO";
	}
	
	return 0;
}