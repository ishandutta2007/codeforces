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
		pair<ll,ll> a[n];
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll br=0;
		fore(i,0,n){
			if(a[i].snd>a[i].fst){
				cout<<"NO\n"; br++; break;
			}
		}
		if(br)continue;
		fore(i,0,n-1){
			if(a[i].fst-a[i].snd>a[i+1].fst-a[i+1].snd||a[i].fst>a[i+1].fst||a[i].snd>a[i+1].snd){
				cout<<"NO\n"; br++; break;
			}
		}
		if(br)continue;
		cout<<"YES\n";
	}
	
	
	return 0;
}