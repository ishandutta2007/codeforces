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

ll num(string s){
	if(s=="M")return 0;
	else if(s.back()=='L')return SZ(s);
	else return -SZ(s);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string a,b; cin>>a>>b;
		auto na=num(a),nb=num(b);
		if(na<nb)cout<<"<\n";
		else if(na==nb)cout<<"=\n";
		else cout<<">\n";
	}
	
	return 0;
}