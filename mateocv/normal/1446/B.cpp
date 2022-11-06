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
typedef int ll;

ll n,m;
string a,b;

ll dp[5005][5005];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	res=0;
	if(x<n)res=max(res,f(x+1,y)-1);
	if(y<m)res=max(res,f(x,y+1)-1);
	if(x<n&&y<m&&a[x]==b[y])res=max(res,f(x+1,y+1)+2);
	return res;
}

int main(){FIN;
	cin>>n>>m>>a>>b;
	mset(dp,-1);
	ll res=0;
	fore(i,0,n){
		fore(j,0,m){
			res=max(res,f(i,j));
		}
	}
	cout<<res<<"\n";
	return 0;
}