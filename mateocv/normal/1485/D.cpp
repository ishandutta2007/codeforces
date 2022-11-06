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
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		fore(j,0,m){
			ll a; cin>>a;
			if((i+j)&1)cout<<"720720 ";
			else cout<<720720-a*a*a*a<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}