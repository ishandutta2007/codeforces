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

const int K=18;

#define oper __gcd
ll st[K][1<<K];ll n;  // K such that 2^K>n
void st_init(vector<ll> &a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
ll st_query(ll s, ll e){
	ll k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> b;
		fore(i,0,n-1)b.pb(abs(a[i]-a[i+1]));
		n--;
		st_init(b);
		ll res=1;
		fore(i,0,n){
			ll l=i+1,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(st_query(i,m)==1)r=m-1;
				else l=m+1;
			}
			res=max(res,r-i+1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}