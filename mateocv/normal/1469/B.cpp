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
		ll resa=0,vaa=0;
		fore(i,0,n){
			vaa+=a[i];
			if(vaa>0){
				resa+=vaa;
				vaa=0;
			}
		}
		ll m; cin>>m;
		ll b[m];
		fore(i,0,m)cin>>b[i];
		ll resb=0,vab=0;
		fore(i,0,m){
			vab+=b[i];
			if(vab>0){
				resb+=vab;
				vab=0;
			}
		}
		cout<<resa+resb<<"\n";
	}
	
	return 0;
}