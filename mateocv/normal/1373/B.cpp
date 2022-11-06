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
	fore(i,0,SZ(s)){
		res+=(s[i]==c);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		if(min(cont(s,'0'),cont(s,'1'))%2==0){
			cout<<"NET\n";
		}else{
			cout<<"DA\n";
		}
	}
	
	return 0;
}