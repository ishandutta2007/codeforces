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
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		//sort(a,a+n);
		ll c[12];
		mset(c,0);
		fore(i,0,n){
			fore(j,0,12){
				if(a[i]==(1<<j)){
					c[j]++;
				}
			}
		}
		fore(j,0,12){
			if(j<11){
				ll r=c[j];
				r/=2;
				c[j+1]+=r;
			}else{
				if(c[j]>0){
					cout<<"YES\n";
				}else{
					cout<<"NO\n";
				}	
			}
		}
	}
	return 0;
}