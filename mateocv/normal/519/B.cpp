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
	ll n,llega,sum=0;cin>>n;
	fore(i,0,n){cin>>llega; sum+=llega;
	}
	ll sum1=sum;
	fore(i,0,n-1){
		cin>>llega;
		sum1-=llega;
	}
	cout<<sum1<<"\n";
	sum1=sum-sum1;
	fore(i,0,n-2){
		cin>>llega;
		sum1-=llega;
	}
	cout<<sum1<<"\n";
	
	return 0;
}