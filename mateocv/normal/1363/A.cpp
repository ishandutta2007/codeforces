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
		ll par[2]={0,0};
		fore(i,0,n){
			ll lle; cin>>lle;
			par[lle%2]++;
		}
		ll br=0;
		fore(i,0,x+1){
			if(i<=par[0]&&x-i<=par[1]){
				if((x-i)%2==1){
					cout<<"Yes\n"; 
					br++; break;
				}
			}
		}
		if(br)continue;
		cout<<"No\n";
	}
	
	return 0;
}