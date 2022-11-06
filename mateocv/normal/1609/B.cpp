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

string s; 

ll ha(ll pos){
	if(pos+2>=SZ(s)||pos<0)return 0;
	string t;
	fore(k,0,3)t+=s[pos+k];
	return t=="abc";
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	cin>>s;
	ll res=0;
	fore(i,0,n)res+=ha(i);
	while(q--){
		ll pos; cin>>pos; pos--;
		char c; cin>>c;
		fore(i,pos-2,pos+1)res-=ha(i);
		s[pos]=c;
		fore(i,pos-2,pos+1)res+=ha(i);
		cout<<res<<"\n";
	}
	
	return 0;
}