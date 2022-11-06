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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll tot=1;
		fore(i,0,n-1){
			tot+=(a[i+1]>a[i]);
		}
		if(k==1){
			if(tot==1){
				cout<<"1\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
		if(tot<=k){
			cout<<"1\n";
		}else{
			cout<<(tot-k+k-2)/(k-1)+1<<"\n";
		}
	}
	
	return 0;
}