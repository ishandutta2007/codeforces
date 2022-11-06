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
	vector<pair<char,ll>> v;
	fore(i,0,n){
		v.pb({s[i],i});
	}
	sort(ALL(v));
	fore(i,0,n){
		if(v[i].fst!=s[i]){
			cout<<"YES\n";
			cout<<i+1<<" "<<v[i].snd+1; return 0;
		}
	}
	cout<<"NO";
	
	return 0;
}