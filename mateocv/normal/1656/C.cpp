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
		sort(ALL(a));
		ll c[3]={0,0,0};
		ll s=0;
		fore(i,0,n){
			if(a[i]<=2)c[a[i]]++;
			if(i<n-1)s+=(a[i+1]==a[i]+1);
		}
		if(c[1]==0||(c[0]==0&&c[2]==0&&s==0))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}