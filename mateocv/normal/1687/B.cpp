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

ll n,m; 

ll ask(string s){
	cout<<"? "<<s<<endl;
	ll res; cin>>res;
	return res;
}

string gets(ll x){
	string res(m,'0');
	res[x]='1';
	return res;
}

int main(){FIN;
	cin>>n>>m;
	vector<ll> v(m);
	fore(i,0,m)v[i]=ask(gets(i));
	vector<pair<ll,ll>> vo;
	fore(i,0,m){
		vo.pb({v[i],i});
	}
	sort(ALL(vo));
	reverse(ALL(vo));
	string s=string(m,'1');
	ll va=ask(s);
	ll res=0;
	fore(i,0,m-1){
		s[vo[i].snd]='0';
		ll nva=ask(s);
		if(nva+vo[i].fst==va){
			s[vo[i].snd]='1';
			res+=vo[i].fst;
		}else va=nva;
	}
	res+=vo.back().fst;
	cout<<"! "<<res<<endl;
	
	return 0;
}