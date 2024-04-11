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

ll sump[200005],a[200005];

ll gets(ll l, ll r){
	return sump[r]-sump[l];
}

ll b[200005];

ll cum(ll l, ll r){
	return r-l>=2&&gets(l+1,r)==(a[l]^a[r]);
}

ll solve(ll l, ll r, ll k){
	//cout<<l<<" "<<r<<" "<<k<<endl;
	if(k==1){
		return max(0ll,r-l-2);
	}
	fore(i,l,r){
		b[i]=a[i]&k;
	}
	vector<ll> v;
	fore(i,l,r){
		if(b[i])v.pb(i);
	}
	ll res=0;
	fore(i,0,SZ(v)){
		fore(j,v[i],(i<SZ(v)-2)?v[i+2]:r){
			res+=cum(v[i],j);
		}
	}
	fore(i,0,SZ(v)){
		fore(j,(i>=2)?v[i-2]+1:l,v[i]){
			res+=cum(j,v[i]);
		}
	}
	fore(i,0,SZ(v)-1){
		res-=cum(v[i],v[i+1]);
	}
	if(SZ(v)){
		fore(i,0,SZ(v)-1){
			res+=solve(v[i]+1,v[i+1],k>>1);
		}
		res+=solve(l,v[0],k>>1);
		res+=solve(v[SZ(v)-1]+1,r,k>>1);
	}else{
		res+=solve(l,r,k>>1);
	}
	//cout<<l<<" "<<r<<" "<<k<<" "<<res<<endl;
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)sump[i+1]=sump[i]+a[i];
	cout<<solve(0,n,(1ll<<29))<<"\n";
	
	return 0;
}