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

ll cont(string s, char c){
	ll res=0;
	for(auto i:s)res+=(i==c);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		string s; cin>>s;
		ll can=0;
		if(x==0)can++;
		if(x>0&&cont(s,'R')>=x)can++;
		if(x<0&&cont(s,'L')>=abs(x))can++;
		if(y==0)can++;
		if(y>0&&cont(s,'U')>=y)can++;
		if(y<0&&cont(s,'D')>=abs(y))can++;
		if(can>=2)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}