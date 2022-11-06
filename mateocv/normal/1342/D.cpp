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
	ll n,k; cin>>n>>k;
	ll t[k],a[n];
	mset(t,0);
	fore(i,0,n){
		cin>>a[i]; a[i]--;
		t[a[i]]++;
	}
	ll c[k];
	fore(i,0,k)cin>>c[i];
	ll sum=0,m=0;
	fore(i,0,k){
		sum+=t[k-1-i];
		m=max(m,(sum+c[k-1-i]-1)/c[k-1-i]);
	}
	vector<ll> res[m];
	sort(a,a+n);
	fore(i,0,n){
		res[i%m].pb(a[i]+1);
	}
	cout<<m<<"\n";
	fore(i,0,m){
		cout<<SZ(res[i])<<" ";
		for(auto j:res[i])cout<<j<<" ";
		cout<<"\n";
	}
	
	return 0;
}