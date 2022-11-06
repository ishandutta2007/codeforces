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
		ll n,x; cin>>n>>x;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll sum=0;
		fore(i,0,n)sum+=a[i];
		if(sum%x!=0){
			cout<<n<<"\n";
		}else{
			ll mini=n,maxi=-1;
			fore(i,0,n){
				if(a[i]%x!=0){
					if(mini==n)mini=i;
					maxi=i;
				}
			}
			if(maxi!=-1)cout<<max(n-1-mini,maxi)<<"\n";
			else cout<<-1<<"\n";
		}
	}
	
	return 0;
}