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
typedef int ll;

const int MOD=1000000007;
int n,t,c[20][2];
map<pair<pair<int,int>,int>,int> m;

ll solve(ll b,ll u,ll ti){
	if(m.count({{b,u},ti}))return m[{{b,u},ti}];
	int &r=m[{{b,u},ti}];
	r=0;
	if(ti+c[u][0]>t)return 0;
	if(ti+c[u][0]==t)return r=1;
	fore(i,0,n){
		if(c[u][1]!=c[i][1]&&(b&(1<<i))==0)r+=solve(b|(1<<u),i,ti+c[u][0]),r%=MOD;
	}
	return r%MOD;
}

int main(){FIN;
	cin>>n>>t;
	fore(i,0,n)cin>>c[i][0]>>c[i][1];
	ll res=0;
	fore(i,0,n)res+=solve(0,i,0),res%=MOD;
	cout<<res;
	
	return 0;
}