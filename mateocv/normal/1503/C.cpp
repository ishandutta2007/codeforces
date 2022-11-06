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
	vector<pair<ll,ll>> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	ll res=0;
	for(auto i:a)res+=i.snd;
	sort(ALL(a));
	ll va=0;
	fore(i,0,n-1){
		va=max(va,a[i].snd);
		ll mini=min(va,a[i+1].fst-a[i].fst);
		va-=mini;
		res+=a[i+1].fst-a[i].fst-mini;
	}
	cout<<res<<"\n";
	
	return 0;
}