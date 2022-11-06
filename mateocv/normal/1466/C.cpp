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

ll dp[100005][2][2];

string s;

ll INF=9e18;

ll f(ll x, ll y, ll z){
	ll &res=dp[x][y][z];
	if(res>=0)return res;
	if(x==SZ(s))return res=0;
	res=f(x+1,z,1)+1;
	if((x<1||s[x]!=s[x-1]||z)&&(x<2||s[x]!=s[x-2]||y)){
		res=min(res,f(x+1,z,0));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		fore(i,0,SZ(s)+1){
			fore(j,0,2){
				fore(k,0,2)dp[i][j][k]=-1;
			}
		}
		cout<<f(0,0,0)<<"\n";
	}
	
	return 0;
}