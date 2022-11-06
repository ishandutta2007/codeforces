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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<ll> mina={a[0]};
		fore(i,1,n)mina.pb(min(a[i],mina.back()));
		vector<ll> maxb={b[0]};
		fore(i,1,n)maxb.pb(max(b[i],maxb.back()));
		ll res=n-1;
		ll l=0,r=n-1;
		while(l<n&&r>=0){
			if(mina[l]<maxb[r]){
				res=min(res,l+r);
				r--;
			}else{
				l++;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}