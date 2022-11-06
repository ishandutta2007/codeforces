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

const ll MOD=1000000007;

ll v2(ll n){
	ll res=0;
	while(n%2==0){
		res++;
		n/=2;
	}
	return res;
}

/*----------------FPOW----------------*/
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> c(32);
	fore(i,0,n)c[v2(a[i])]++;
	ll s=n;
	ll res=(fpow(2,c[0])-1)*fpow(2,s-c[0])%MOD;
	s-=c[0];
	fore(i,1,32){
		if(c[i]==0)continue;
		res=(res+(fpow(2,c[i]-1)-1)*fpow(2,s-c[i]))%MOD;
		s-=c[i];
	}
	cout<<res<<"\n";
	
	return 0;
}