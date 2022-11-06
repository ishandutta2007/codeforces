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

const ll MOD=998244353;

string a,b;

ll dp[1010][1010][3][4];

ll add(ll x, ll y){
	ll res=x+y;
	if(res>=MOD)res-=MOD;
	return res;
}

ll f(ll x, ll y, ll u, ll mk){
	ll &res=dp[x][y][u][mk];
	if(res>=0)return res;
	res=0;
	if(mk==3)res++;
	char c='.';
	if(u==0)c=a[x-1];
	if(u==1)c=b[y-1];
	if(x<SZ(a)&&c!=a[x])res=add(res,f(x+1,y,0,mk|1));
	if(y<SZ(b)&&c!=b[y])res=add(res,f(x,y+1,1,mk|2));
	return res;
}

int main(){FIN;
	cin>>a>>b;
	mset(dp,-1);
	ll res=0;
	fore(i,0,SZ(a)){
		fore(j,0,SZ(b)){
			res=add(res,f(i,j,2,0));
		}
	}
	cout<<res<<"\n";
	
	return 0;
}