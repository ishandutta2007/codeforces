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

string solve(ll n, ll va){
	string res;
	if(n<=5){
		assert(va+5<=26);
		fore(i,0,n)res+='a'+va,va++;
	}else{
		if(n%3==0){
			assert(va+1<=26);
			string c;
			c+='a'+va;
			res=solve(n-1,va+1)+c;
		}else if(n%3==1){
			assert(va+1<=26);
			string c;
			c+='a'+va;
			res=c+c+c+solve(n-5,va+1)+c+c;
		}else{
			assert(va+1<=26);
			string c;
			c+='a'+va;
			auto s=solve((n-5)/3,va+1);
			res=c+s+c+s+c+c+s+c;
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<solve(n,0)<<"\n";
	}
	
	return 0;
}