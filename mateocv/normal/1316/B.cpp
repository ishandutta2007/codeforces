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
		string s; cin>>s;
		pair<string,ll> a[n];
		fore(i,1,n+1){
			string r;
			fore(j,0,i-1)r+=s[j];
			if((n-i+1)%2)reverse(ALL(r));
			string rr;
			fore(j,i-1,n)rr+=s[j];
			a[i-1]={rr+r,i};
		}
		auto res=a[0];
		fore(i,0,n)res=min(res,a[i]);
		cout<<res.fst<<"\n"<<res.snd<<"\n";
	}
	
	return 0;
}