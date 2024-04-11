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
	map <char,ll> cant;
	map <pair<char,char>,ll> res;
	fore(i,0,SZ(s)){
		for(auto j:cant){
			res[{j.fst,s[i]}]+=j.snd;
		}
		cant[s[i]]++;
	}
	ll resf=0;
	for(auto i:cant){
		resf=max(resf,i.snd);
	}
	for(auto i:res){
		resf=max(resf,i.snd);
	}
	cout<<resf;
	return 0;
}