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
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		string s[n];
		fore(i,0,n)cin>>s[i];
		ll par=1,c=0;
		fore(i,0,n){
			par&=(SZ(s[i])%2==0);
			fore(j,0,SZ(s[i]))c+=(s[i][j]=='0');
		}
		if(par&&(c&1)){
			cout<<n-1<<"\n";
		}else{
			cout<<n<<"\n";
		}
	}
	
	return 0;
}