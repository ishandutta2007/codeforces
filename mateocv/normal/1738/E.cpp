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

const ll MOD=998244353;
const int MAXN=100005;

ll fact[MAXN],facti[MAXN];

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*(facti[n-k]*facti[k]%MOD)%MOD;
}

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll calc(ll x, ll y){
	ll res=0;
	fore(i,0,min(x,y)+1){
		res=(res+comb(x,i)*comb(y,i))%MOD;
	}
	return res;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	facti[MAXN-1]=fpow(fact[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)facti[i]=(facti[i+1]*(i+1))%MOD;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> c[2];
		ll l=0,r=n-1;
		ll sl=0,sr=0;
		while(1){
			ll cl=0;
			while(l<n&&a[l]==0)cl++,l++;
			c[0].pb(cl);
			if(l>r)break;
			ll cr=0;
			while(r>=0&&a[r]==0)cr++,r--;
			c[1].pb(cr);
			if(l>r)break;
			sl=a[l];
			l++;
			sr=a[r];
			r--;
			while(l<=r&&sl!=sr){
				if(sl<sr){
					sl+=a[l]; l++;
				}else{
					sr+=a[r]; r--;
				}
			}
			if(l>r+1)break;
			if(l==r+1){
				if(sl==sr)c[0].pb(0);
				break;
			}
		}
		fore(k,0,2)reverse(ALL(c[k]));
		/*
		fore(k,0,2){
			for(auto i:c[k])cout<<i<<" ";
			cout<<"\n";
		}
		*/
		ll res=1,ya=0;
		while(SZ(c[0])&&SZ(c[1])){
			res=res*calc(c[0].back()+ya,c[1].back()+ya)%MOD;
			fore(k,0,2)c[k].pop_back();
			ya=1;
		}
		if(SZ(c[0])){
			res=res*fpow(2,c[0][0]-1+2*ya)%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}