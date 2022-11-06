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
		ll n,k,x; cin>>n>>k>>x; x--;
		string s; cin>>s;
		vector<ll> c,v;
		fore(i,0,SZ(s)){
			if(s[i]=='*'){
				if(i==0||s[i-1]!='*')c.pb(1);
				else c[SZ(c)-1]++;
			}
		}
		if(SZ(c))reverse(ALL(c));
		//for(auto i:c)cout<<i<<" ";
		//cout<<endl;
		ll pos=0;
		while(x){
			v.pb(x%(c[pos]*k+1));
			x/=c[pos]*k+1;
			pos++;
		}
		while(SZ(v)<SZ(c))v.pb(0);
		fore(i,0,SZ(s)){
			if(s[i]=='a')cout<<'a';
			else if(i==0||s[i-1]=='a'){
				auto b=v.back();
				v.pop_back();
				fore(_,0,b)cout<<'b';
			}
		}
		cout<<"\n";
	}
	
	return 0;
}