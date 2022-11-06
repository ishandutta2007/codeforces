#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

//ll pot[21];

ll ap(ll &n,ll k){
	fore(i,0,k){
		n^=(1<<i);
	}
}

ll es(ll n){
	fore(i,0,21){
		if(n==(1<<i)-1){
			return 1;
		}
	}
	return 0;
}

int main(){FIN;
	ll n; cin>>n;
	/*fore(i,0,21){
		pot[i]=(1<<(i+1))-1;
	}*/
	vector<ll> v;
	ll res=0;
	for(int i=19;i>=0;i--){
		if(es(n))break;
		if(!(n&(1<<i))){
			ap(n,i+1); res++; v.pb(i+1);
			if(es(n))break;
			n++; res++;
		}
		if(es(n))break;
	}
	cout<<res<<"\n";
	fore(i,0,SZ(v))cout<<v[i]<<" ";
	
	return 0;
}