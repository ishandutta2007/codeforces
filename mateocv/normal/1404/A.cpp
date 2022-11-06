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

set<char> val[300005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		fore(i,0,k)val[i].clear();
		fore(i,0,n){
			if(s[i]!='?'){
				val[i%k].insert(s[i]);
			}
		}
		ll br=0;
		fore(i,0,k){
			if(SZ(val[i])>=2){
				br++; break;
			}
		}
		if(br){
			cout<<"NO\n";
			continue; 
		}
		ll c[2]={0,0};
		fore(i,0,k){
			if(SZ(val[i])){
				c[*val[i].begin()-'0']++;
			}
		}
		if(c[0]>k/2||c[1]>k/2){
			cout<<"NO\n"; continue;
		}else{
			cout<<"YES\n";
		}
	}
	
	return 0;
}