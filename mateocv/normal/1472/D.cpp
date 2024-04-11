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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll val=0;
		sort(a,a+n);
		reverse(a,a+n);
		fore(i,0,n){
			if(i&1){
				if(a[i]&1){
					val-=a[i];
				}
			}else{
				if(a[i]%2==0){
					val+=a[i];
				}
			}
		}
		if(val>0){
			cout<<"Alice\n";
		}else if(val==0){
			cout<<"Tie\n";
		}else{
			cout<<"Bob\n";
		}
	}
	
	return 0;
}