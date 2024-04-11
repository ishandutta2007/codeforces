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
		string s; cin>>s;
		ll br=0;
		fore(i,n/2,n){
			if(s[i]=='0'){
				cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		if(s[n/2-1]=='0'){
			cout<<n/2<<" "<<n<<" "<<n/2+1<<" "<<n<<"\n";
		}else{
			cout<<n/2<<" "<<n-1<<" "<<n/2+1<<" "<<n<<"\n";
		}
	}
	
	return 0;
}