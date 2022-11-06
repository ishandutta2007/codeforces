#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll solve(string &s){
	ll res=0;
	//fore(i,0,SZ(s))res+=(s[i]=='1');
	//fore(i,0,SZ(s)-1)res+=(s[i]=='1'&&s[i+1]=='0');
	vector<pair<ll,ll>> v;
	ll va=0;
	fore(i,0,SZ(s)){
		if(s[i]=='0')va++;
		else{
			v.pb({va,i});
			va=0;
		}
	}
	fore(i,0,SZ(v)){
		ll pa=0;
		fore(j,0,20){
			if(v[i].snd+j<SZ(s)){
				pa*=2;
				pa+=(s[v[i].snd+j]=='1');
				if(v[i].fst>=pa-j-1)res++;
			}
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		cout<<solve(s)<<"\n";
	}
	
	return 0;
}