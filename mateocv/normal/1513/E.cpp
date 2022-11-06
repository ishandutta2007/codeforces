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

const int MAXN=100005;

ll fact[MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

vector<ll> vc(vector<ll> v){
	sort(ALL(v));
	vector<ll> res;
	fore(i,0,SZ(v)){
		if(i==0||v[i]!=v[i-1])res.pb(1);
		else res[SZ(res)-1]++;
	}
	return res;
}

ll combg(vector<ll> v){
	ll s=0;
	for(auto i:v)s+=i;
	ll res=1;
	for(auto i:v)res=res*fact[i]%MOD;
	res=fpow(res,MOD-2);
	res=res*fact[s]%MOD;
	return res;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll s=0;
	for(auto i:a)s+=i;
	if(s%n!=0){
		cout<<"0\n";
		return 0;
	}
	ll p=s/n;
	ll res=1;
	ll c[3]={0,0,0};
	for(auto i:a){
		if(i<p)c[0]++;
		if(i==p)c[1]++;
		if(i>p)c[2]++;
	}
	if(min(c[0],c[2])<=1)res=res*combg(vc(a))%MOD;
	else{
		res=res*combg({c[1],n-c[1]})%MOD;
		vector<ll> v[2];
		for(auto i:a){
			if(i<p)v[0].pb(i);
			if(i>p)v[1].pb(i);
		}
		res=res*2ll%MOD;
		res=res*combg(vc(v[0]))%MOD;
		res=res*combg(vc(v[1]))%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}