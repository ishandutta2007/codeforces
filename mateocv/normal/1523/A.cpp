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

string upd(string s){
	string res=s;
	if(s[1]=='1')res[0]='1';
	if(s[SZ(s)-2]=='1')res[SZ(s)-1]='1';
	fore(i,1,SZ(s)-1){
		if(s[i]=='0'){
			if((s[i-1]=='1')^(s[i+1]=='1'))res[i]='1';
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		string s; cin>>s;
		fore(i,0,m){
			string ss=upd(s);
			if(s==ss)break;
			s=ss;
		}
		cout<<s<<"\n";
	}
	
	return 0;
}