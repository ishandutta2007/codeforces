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

vector<ll> a;

vector<pair<ll,ll>> res;

void oper(ll l, ll r){
	res.pb({l,r});
	if((a[l]+a[r])&1)a[r]=a[l];
	else a[l]=a[r];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		res.clear();
		oper(0,n-1);
		fore(i,1,n-1){
			if((a[0]+a[i])&1)oper(0,i);
			else oper(i,n-1);
		}
		fore(i,1,n)assert(a[i-1]<=a[i]);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}