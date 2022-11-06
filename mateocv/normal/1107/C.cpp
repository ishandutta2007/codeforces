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
	ll golp[n];
	fore(i,0,n) cin>>golp[i];
	char act='A', llega;
	ll sum=0;/*
	ll van=0,l=0,r=0, guar[200005];
	while(van<n){
		cin>>llega;
		guar[]
		if(llega!=act){
			r=van;
			
			
			
			
			act=llega;
			l=van
		}
		van++;
	}*/
	vector<ll> v;
	fore(i,0,n+1){
		if(i<n){cin>>llega;
		}else{llega='A';
		}
		if(llega!=act){
			act=llega;
			sort(v.begin(),v.end());
			fore(i,0,min(k,1LL*SZ(v))){
				sum+=v.back(); v.pop_back();
			}
			v.clear();
//			cout<<sum<<endl;
			
		}
		if(i<n) v.pb(golp[i]);
		
	}
	
	cout<<sum;
	
	return 0;
}