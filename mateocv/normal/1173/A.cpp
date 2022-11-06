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

int main(){FIN;
	ll x,y,z; cin>>x>>y>>z;
	vector<char> res;
	if((x+y+z)%2==0&&abs(x-y)<=z){
		res.pb('0');
	}
	if(x+z>y){
		res.pb('+');
	}
	if(y+z>x){
		res.pb('-');
	}
	if(SZ(res)==1){
		cout<<res[0];
	}else{
		cout<<'?';
	}
	
	return 0;
}