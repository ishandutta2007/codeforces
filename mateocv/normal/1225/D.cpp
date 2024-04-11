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

vector<pair<ll,ll>> fact(ll n){
	vector<pair<ll,ll>> res;
	for(ll i=2;i*i<=n;i++){
		ll va=0;
		while(n%i==0){
			va++;
			n/=i;
		}
		if(va>0)res.pb({i,va});
	}
	if(n>1){
		res.pb({n,1});
	}
	return res;
}

ll k;

ll red(ll n){
	auto f=fact(n);
	fore(i,0,SZ(f)){
		f[i].snd%=k;
	}
	ll res=1;
	fore(i,0,SZ(f)){
		fore(j,0,f[i].snd)res*=f[i].fst;
	}
	return res;
}

ll comp(ll n){
	auto f=fact(n);
	fore(i,0,SZ(f)){
		f[i].snd=(k-f[i].snd)%k;
	}
	ll res=1;
	fore(i,0,SZ(f)){
		fore(j,0,f[i].snd){
			res*=f[i].fst;
			if(res>100000)return -1;
		}
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)a[i]=red(a[i]);
	ll c[100005];
	mset(c,0);
	fore(i,0,n){
		c[a[i]]++;
	}
	ll res=0;
	fore(i,0,n){
		ll cc=comp(a[i]);
		if(cc==-1)continue;
		res+=c[cc]-(a[i]==cc);
		//cout<<c[cc]<<" ";
	}
	cout<<res/2;
	return 0;
}