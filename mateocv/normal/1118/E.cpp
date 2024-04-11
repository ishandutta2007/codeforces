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
	ll n,k; cin>>n>>k;
	if(k*(k-1)<n){cout<<"NO";
	}else{
		cout<<"YES\n";
		ll a=1,b=2;
		fore(i,0,n){
			if(i%2){
				cout<<b<<" "<<a<<"\n";
				if(b!=k){b++;
				}else{
					a++;
					b=a+1;
				}
				
			}else{
				cout<<a<<" "<<b<<"\n";
			}
		}
		
	}
	
	return 0;
}