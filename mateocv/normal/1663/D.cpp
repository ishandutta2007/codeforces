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
	string s; cin>>s;
	ll x; cin>>x;
	bool res=0;
	if(s=="ABC"){
		res=(x<=1999);
	}else if(s=="ARC"){
		res=(x<=2799);
	}else if(s=="AGC"){
		res=(x>=1200);
	}else assert(0);
	if(res)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}