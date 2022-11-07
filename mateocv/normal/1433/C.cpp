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
		ll maxi=0;
		fore(i,0,n)maxi=max(maxi,a[i]);
		ll tot=0,res=-1;
		fore(i,0,n)tot+=(a[i]==maxi);
		if(tot==n){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,n){
			if(i+1<n&&a[i]==maxi&&a[i+1]!=maxi){
				res=i; break;
			}
			if(i-1>=0&&a[i]==maxi&&a[i-1]!=maxi){
				res=i; break;
			}
		}
		assert(res!=-1);
		cout<<res+1<<"\n";
	}
	
	return 0;
}