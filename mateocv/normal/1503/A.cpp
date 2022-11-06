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
		ll c=0;
		for(auto i:s)c+=(i=='0');
		if((c&1)||s[0]=='0'||s.back()=='0'){
			cout<<"NO\n";
		}else{
			ll a=0,b=0;
			pair<string,string> res;
			for(auto i:s){
				if(i=='0'){
					if(b&1)res.fst+=')',res.snd+='(';
					else res.fst+='(',res.snd+=')';
					b++;
				}else{
					if(a<(SZ(s)-c)/2)res.fst+='(',res.snd+='(';
					else res.fst+=')',res.snd+=')';
					a++;
				}
			}
			cout<<"YES\n"<<res.fst<<"\n"<<res.snd<<"\n";
		}
	}
	
	return 0;
}