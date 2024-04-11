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

vector<ll> a;

bool dp[102][400005];

bool vis[102][400005];

bool f(ll x, ll y){
	auto &res=dp[x][y];
	if(vis[x][y])return res;
	vis[x][y]=1;
	if(x==SZ(a))return res=(y==200000);
	res=(f(x+1,y+a[x])||f(x+1,y-a[x]));
	return res;
}

ll v2(ll n){
	ll res=0;
	while(n%2==0)res++,n/=2;
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	if(f(0,200000)){
		pair<ll,ll> mini={40,-1};
		fore(i,0,n){
			mini=min(mini,{v2(a[i]),i});
		}
		cout<<"1\n"<<mini.snd+1<<"\n";
	}else{
		cout<<"0\n";
	}
	
	return 0;
}