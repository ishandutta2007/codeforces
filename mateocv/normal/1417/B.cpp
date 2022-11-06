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
		ll n,s; cin>>n>>s;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		if(s&1){
			fore(i,0,n){
				cout<<(a[i]<=s/2)<<" ";
			}
		}else{
			ll va=0;
			fore(i,0,n){
				if(a[i]==s/2){
					cout<<va<<" ";
					va^=1;
				}else cout<<(a[i]<s/2)<<" ";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}