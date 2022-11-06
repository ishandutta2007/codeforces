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
	fore(i,0,SZ(s))res+=(s[i]==c);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll p=cont(s,'P');
		ll r=cont(s,'R');
		ll ss=cont(s,'S');
		ll m=max({r,p,ss});
		if(m==p){
			fore(i,0,SZ(s))cout<<"S";
		}else if(m==ss){
			fore(i,0,SZ(s))cout<<"R";
		}else if(m==r){
			fore(i,0,SZ(s))cout<<"P";
		}
		cout<<"\n";
	}
	
	return 0;
}