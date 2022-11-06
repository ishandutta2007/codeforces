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
		ll n,r,b; cin>>n>>r>>b;
		ll c=r/(b+1);
		fore(i,0,b+1){
			fore(_,0,c+(i<r%(b+1)))cout<<"R";
			if(i<b)cout<<"B";
		}
		cout<<"\n";
	}
	
	return 0;
}