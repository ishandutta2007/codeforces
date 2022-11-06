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
		vector<pair<ll,ll>> v;
		fore(i,0,9)v.pb({(i%3)*3+(i/3),i});
		char a[9][9];
		fore(i,0,9){
			fore(j,0,9){
				cin>>a[i][j];
			}
		}
		for(auto i:v){
			a[i.fst][i.snd]='1'+(a[i.fst][i.snd]-'1'+1)%9;
			//cout<<i.fst<<" "<<i.snd<<"\n";
		}
		fore(i,0,9){
			fore(j,0,9)cout<<a[i][j];
			cout<<"\n";
		}
	}
	
	return 0;
}