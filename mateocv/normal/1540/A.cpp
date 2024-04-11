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

void printi(__int128 n){
	string s;
	while(n){
		s+='0'+n%10;
		n/=10;
	}
	reverse(ALL(s));
	cout<<s<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<ll> aa;
		fore(i,0,n-1)aa.pb(a[i+1]-a[i]);
		vector<ll> c(n-1);
		fore(i,0,n-1){
			c[i]=(i+1)*(n-1-i)-1;
		}
		__int128 res=0;
		fore(i,0,n-1)res+=aa[i]*c[i];
		if(res==0)cout<<"0\n";
		else{
			cout<<"-";
			printi(res);
		}
	}
	
	return 0;
}