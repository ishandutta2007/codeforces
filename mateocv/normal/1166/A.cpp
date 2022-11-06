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
	string s[n];
	fore(i,0,n)cin>>s[i];
	//sort(s,s+n);
	ll l[30];
	mset(l,0);
	fore(i,0,n){
		l[0+s[i][0]-'a']++;
	}
	ll res=0;
	fore(i,0,26){
		ll vap=l[i]/2;
		res+=((vap)*(vap-1))/2+((l[i]-vap)*(l[i]-vap-1))/2;
	}
	cout<<res;
	return 0;
}