#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,x,y; cin>>n>>x>>y;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		ll br=0;
		fore(j,max(i-x,0ll),i){
			if(a[j]<=a[i]){
				 br++; break;
			}
		}
		if(br)continue;
		fore(j,i+1,min(i+y+1,n)){
			if(a[j]<=a[i]){
				 br++; break;
			}
		}
		if(br)continue;
		cout<<i+1; return 0;
	}
	
	return 0;
}