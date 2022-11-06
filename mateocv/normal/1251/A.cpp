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
		string s; cin>>s;
		char va='.';
		ll van=0;
		set<char> res;
		fore(i,0,SZ(s)){
			if(s[i]==va)van++;
			else{
				if(van%2==1&&va!='.')res.insert(va);
				va=s[i];
				van=1;
			}
			if(i==SZ(s)-1){
				if(van%2==1&&va!='.')res.insert(va);
			}
		}
		for(auto i:res)cout<<i; cout<<"\n";
	}
	
	return 0;
}