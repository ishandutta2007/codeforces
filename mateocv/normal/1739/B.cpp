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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> res={a[0]};
		fore(i,1,n)res.pb(res.back()+a[i]);
		ll br=0;
		fore(i,1,n){
			if(a[i]>0&&a[i]<=res[i-1])br=1;
		}
		if(br)cout<<"-1\n";
		else{
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}