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
		ll br=0;
		fore(i,0,n-1)br+=(a[i]>a[i+1]);
		if(!br){
			cout<<"0\n";
			continue;
		}
		if(a[0]==1||a[n-1]==n){
			cout<<"1\n";
			continue;
		}
		if(a[0]==n&&a[n-1]==1){
			cout<<"3\n";
			continue;
		}
		cout<<"2\n";
	}
	
	return 0;
}