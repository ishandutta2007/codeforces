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
		vector<ll> b={a[0]};
		fore(i,1,n){
			if(a[i]!=b.back())b.pb(a[i]);
		}
		ll c=0;
		fore(i,0,SZ(b)){
			c+=((i==0||b[i-1]>b[i])&&(i==SZ(b)-1||b[i+1]>b[i]));
		}
		if(c==1)cout<<"Yes\n";
		else cout<<"nO\n";
	}
	
	return 0;
}