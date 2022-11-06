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
 
ll contar(string &s, char c){
	ll res=0;
	fore(i,0,SZ(s)){
		res+=(s[i]==c);
	}
	return res;
}
 
int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll r=contar(s,'R');
	ll l=contar(s,'L');
	cout<<r+l+1;	
	return 0;
}