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
		ll n,k; cin>>n>>k;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(a,a+n); reverse(a,a+n);
		sort(b,b+n); reverse(b,b+n);
		ll res=0;
		fore(i,0,n-k){
			res+=a[i];
		}
		ll l=n-k,r=0;
		fore(i,0,k){
			if(r>=n||a[l]>b[r]){
				res+=a[l]; l++;
			}else if(l>=n||b[r]>=a[l]){
				res+=b[r]; r++;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}