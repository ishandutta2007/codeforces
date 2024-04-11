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
	ll n; cin>>n;
	while(n--){
		string s,t; cin>>s>>t;
		vector<pair<ll,char>> v[2];
		char va='.'; ll van=0;
		fore(i,0,SZ(s)){
			if(s[i]==va)van++;
			else{
				v[0].pb({van,va});
				va=s[i]; van=1;
			}
			if(i==SZ(s)-1){
				v[0].pb({van,va});
			}
		}
		va='.'; van=0;
		fore(i,0,SZ(t)){
			if(t[i]==va)van++;
			else{
				v[1].pb({van,va});
				va=t[i]; van=1;
			}
			if(i==SZ(t)-1){
				v[1].pb({van,va});
			}
		}
		if(SZ(v[0])!=SZ(v[1])){
			cout<<"NO\n"; continue;
		}
		fore(i,0,SZ(v[0])){
			if(v[1][i].snd!=v[0][i].snd||v[1][i].fst<v[0][i].fst){
				cout<<"NO\n"; break;
			}
			if(i==SZ(v[0])-1){
				cout<<"YES\n";
			}
		}
	}
	
	return 0;
}