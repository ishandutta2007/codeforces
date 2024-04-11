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
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> d;
	fore(i,0,n-1)d.pb(a[i+1]>a[i]);
	vector<ll> c;
	ll va=0;
	fore(i,0,SZ(d)){
		va++;
		if(i==SZ(d)-1||d[i]!=d[i+1])c.pb(va),va=0;
	}
	pair<ll,ll> maxi={0,-1};
	fore(i,0,SZ(c))maxi=max(maxi,{c[i],i});
	ll cant=0;
	fore(i,0,SZ(c))cant+=(c[i]==maxi.fst);
	ll res=0;
	if(cant==2&&maxi.snd-1>=0&&c[maxi.snd-1]==maxi.fst&&(maxi.fst%2==0)){
		res=d[0]^((maxi.snd-1)&1);
	}
	cout<<res<<"\n";
	
	return 0;
}