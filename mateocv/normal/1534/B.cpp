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
		vector<ll> a(n+2);
		a[0]=0,a[n+1]=0;
		fore(i,1,n+1)cin>>a[i];
		n+=2;
		ll res=0;
		fore(i,1,n-1){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				res+=a[i]-max(a[i-1],a[i+1]);
				a[i]=max(a[i-1],a[i+1]);
			}
		}
		fore(i,0,n-1)res+=abs(a[i+1]-a[i]);
		cout<<res<<"\n";
	}
	
	return 0;
}