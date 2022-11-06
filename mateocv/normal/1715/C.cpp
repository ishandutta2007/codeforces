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
	ll n,m; cin>>n>>m;
	vector<ll> c(n-1);
	fore(i,0,n-1)c[i]=(i+1)*(n-i-1);
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll res=n*(n-1)/2+n;
	fore(i,0,n-1)res+=(a[i]!=a[i+1])*c[i];
	while(m--){
		ll pos,val; cin>>pos>>val; pos--;
		if(pos<n-1)res-=(a[pos]!=a[pos+1])*c[pos];
		if(pos>0)res-=(a[pos]!=a[pos-1])*c[pos-1];
		a[pos]=val;
		if(pos<n-1)res+=(a[pos]!=a[pos+1])*c[pos];
		if(pos>0)res+=(a[pos]!=a[pos-1])*c[pos-1];
		cout<<res<<"\n";
	}
	return 0;
}