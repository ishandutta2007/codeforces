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
	int n; cin>>n;
	double EPS=1e-9;
	while(n--){
		ll a, b; cin>>a>>b;
		ll tot=a*b;
		ll r=cbrt(1.*tot)+EPS;
		
	//	ll r=pow(1.*tot,1./3)+EPS;
	//	ll rp=r+EPS;
	//	cout<<r<<" "<<rp<<endl;
		if(r*r*r==tot){
			if((a%r==0)&&(b%r==0)){cout<<"Yes"<<"\n";
			}else{cout<<"No"<<"\n";
			}
		}else{cout<<"No"<<"\n";
		}
	}
	
	return 0;
}