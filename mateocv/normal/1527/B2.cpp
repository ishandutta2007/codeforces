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

const int MAXN=1010;

ll vis[MAXN][MAXN][2][2];
ll dp[MAXN][MAXN][2][2];

ll f(ll x, ll y, ll z, ll b){
	ll &res=dp[x][y][z][b];
	if(vis[x][y][z][b])return res;
	vis[x][y][z][b]=1;
	if(x+y+z==0)return res=0;
	res=1e18;
	if(x)res=min(res,1-f(x-1,y+1,z,1));
	if(y)res=min(res,1-f(x,y-1,z,1));
	if(z)res=min(res,1-f(x,y,z-1,1));
	if(b&&y)res=min(res,-f(x,y,z,0));
	//cout<<x<<" "<<y<<" "<<z<<" "<<b<<" "<<res<<"\n";
	return res;	
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll a=0,b=0,c=0;
		fore(i,0,n){
			if(i<n-1-i){
				if(s[i]==s[n-i-1]&&s[i]=='0')a++;
				if(s[i]!=s[n-i-1])b++;
			}
		}
		if(n%2==1&&s[n/2]=='0')c++;
		ll res=f(a,b,c,1);
		if(res<0)cout<<"ALICE\n";
		else if(res==0)cout<<"DRAW\n";
		else cout<<"BOB\n";
	}
	
	return 0;
}