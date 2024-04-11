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

string s;

ll solve(ll l, ll r, char c){
	if(r-l==1)return s[l]!=c;
	ll tot[2]={0,0};
	fore(i,l,(l+r)/2)tot[0]+=(s[i]!=c);
	fore(i,(l+r)/2,r)tot[1]+=(s[i]!=c);
	return min(solve(l,(l+r)/2,c+1)+tot[1],solve((l+r)/2,r,c+1)+tot[0]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cin>>s;
		cout<<solve(0,SZ(s),'a')<<"\n";
	}
	
	return 0;
}