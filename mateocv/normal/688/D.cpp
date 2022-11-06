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

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll> v;
	for(int i=2;i*i<=k;i++){
		if(k%i==0){
			ll tot=1;
			while(k%i==0)tot*=i,k/=i;
			v.pb(tot);
		}
	}
	if(k!=1)v.pb(k);
	ll cum[SZ(v)];
	fore(i,0,n){
		fore(j,0,SZ(v)){
			if(a[i]%v[j]==0)cum[j]=1;
		}
	}
	ll tot=0;
	fore(i,0,SZ(v)){
		tot+=cum[i];
	}

	if(tot==SZ(v)){
		cout<<"Yes";
	}else{
		cout<<"No";
	}

	return 0;
}