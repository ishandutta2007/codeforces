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

ll contar(char c,string s){
	ll res=0;
	fore(i,0,SZ(s)){
		res+=(s[i]==c);
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll z=contar('z',s);
	ll e=contar('e',s);
	ll r=contar('r',s);
	ll o=contar('o',s);
	ll nn=contar('n',s);
	fore(i,0,nn){
		cout<<1<<" ";
	}
	fore(i,0,z){
		cout<<0<<" ";
	}
	
	return 0;
}