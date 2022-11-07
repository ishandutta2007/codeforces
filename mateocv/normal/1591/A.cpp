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
		ll res=1;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			if(i){
				if(a[i]==0&&a[i-1]==0){
					res=-1; break;
				}else if(a[i]==1&&a[i-1]==0){
					res++;
				}else if(a[i]==1&&a[i-1]==1){
					res+=5;
				}
			}else{
				res+=a[i];
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}