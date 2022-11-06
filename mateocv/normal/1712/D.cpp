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

ll M=1000000000;

ll calc(vector<ll> a, ll m){
	vector<ll> v;
	ll res=0;
	fore(i,0,SZ(a)){
		if(2ll*a[i]<m)a[i]=M,res++;
	}
	ll br=0,ex=0;
	fore(i,0,SZ(a)-1){
		if(a[i]>=m&&a[i+1]>=m)br++;
	}
	fore(i,0,SZ(a))ex+=(a[i]>=m);
	if(!br){
		if(ex)res++;
		else res+=2;
	}
	//cout<<m<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll l=0,r=M;
		while(l<=r){
			ll m=(l+r)/2;
			if(calc(a,m)<=k)l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}