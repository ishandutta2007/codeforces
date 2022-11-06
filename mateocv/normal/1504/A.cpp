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

bool ispal(string s){
	string ss=s;
	reverse(ALL(ss));
	return s==ss;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		if(!ispal("a"+s)){
			cout<<"YES\n"<<"a"+s<<"\n";
		}else if(!ispal(s+"a")){
			cout<<"YES\n"<<s+"a"<<"\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}