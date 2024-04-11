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
		ll n,x,y; cin>>n>>x>>y;
		if(x>y)swap(x,y);
		if(x!=0||y==0||(n-1)%y){
			cout<<"-1\n";
			continue;
		}
		vector<ll> res(n-1);
		fore(i,0,(n-1)/y){
			fore(j,i*y,i*y+y){
				res[j]=i*y+2;
			}
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}