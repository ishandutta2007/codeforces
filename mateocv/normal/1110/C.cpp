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


ll maxg(ll x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){return x/i;
		}
	}
	return 1;
}

int main(){FIN;
	
	ll q,a; cin>>q;
	double eps=1e9;
	while(q--){
		cin>>a;
		ll cant=1ll*log2(a)+eps+1;
		if(a==(1<<cant)-1){cout<<maxg(a)<<"\n";
		}else{
			ll op=(1<<cant)-1;
			cout<<op<<"\n";
		}
	}
	
	return 0;
}