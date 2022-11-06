#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll res[n];
	vector<pair<char,ll>> v;
	fore(i,0,n){
		if(SZ(v)==0||s[i]=='(')v.pb({s[i],i});
		else{
			res[i]=(SZ(v))%2;
			res[v.back().snd]=(SZ(v))%2;
			v.pop_back();
		}
	}
	fore(i,0,n)cout<<res[i];
	
	return 0;
}