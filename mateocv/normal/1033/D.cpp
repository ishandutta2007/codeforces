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

ll mult(ll n, ll s){
	ll res=1;
	fore(i,0,s)res*=n;
	return res;
}

ll root(ll n, ll s){
	ll res=pow(n,1./s)-3;
	while(res<0||mult(res,s)<n)res++;
	if(mult(res,s)==n)return res;
	return -1;
}

/*ll esp(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}*/

const ll MOD=998244353;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	map<ll,ll> f;
	map<ll,ll> r;
	fore(i,0,n){
		if(root(a[i],4)!=-1){
			f[root(a[i],4)]+=4;
		}else if(root(a[i],3)!=-1){
			f[root(a[i],3)]+=3;
		}else if(root(a[i],2)!=-1){
			f[root(a[i],2)]+=2;
		}else{
			r[a[i]]++;
		}
	}
	ll res=1;
	for(auto i:r){
		ll br=0;
		fore(j,0,n){
			ll g=__gcd(i.fst,a[j]);
			if(g!=1&&g!=i.fst){
				f[g]+=i.snd;
				f[i.fst/g]+=i.snd;
				br++; break;
			}
		}
		if(br)continue;
		res*=(i.snd+1)*(i.snd+1);
		//cout<<"Multplico por "<<(i.snd+1)*(i.snd+1)<<"\n";
		res%=MOD;
	}
	for(auto i:f){
		res*=i.snd+1;
		res%=MOD;
	}
	cout<<res<<endl;
	return 0;
}