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
		ll res=0;
		fore(i,0,n){
			ll l=0,r=0,sum=0;
			while(r<n+1){
				if(sum==a[i]&&r-l>1){
					res++; break;
				}else if(sum<a[i]){
					if(r==n)break;
					sum+=a[r];
					r++;
				}else if(sum>=a[i]){
					sum-=a[l];
					l++;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}