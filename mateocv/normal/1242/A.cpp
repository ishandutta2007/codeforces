#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

map<ll,ll> fact(ll n){
    map<ll,ll> res;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            res[i]++; n/=i;
        }
    }
    if(n>1){
        res[n]++;
    }
    return res;
}

int main(){FIN;
	ll n; cin>>n;
	if(n==1){
	    cout<<1; return 0;
	}
	map<ll,ll> f=fact(n);
	if(SZ(f)>=2){
	    cout<<1; return 0;
	}else{
	    for(auto i:f){
	        cout<<i.fst;
	    }
	    return 0;
	}
	return 0;
}