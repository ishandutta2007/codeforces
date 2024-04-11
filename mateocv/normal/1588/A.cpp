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

const int MAXN=105,MAXM=105;

vector<int> g[MAXN]; // [0,n)->[0,m)
int n,m;
int mat[MAXM];bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int> > max_matching(){
	vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		m=n;
		vector<ll> a(n);
		vector<ll> b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n)g[i].clear();
		fore(i,0,n){
			fore(j,0,m){
				if(b[j]==a[i]||b[j]==a[i]+1)g[i].pb(j);
			}
		}
		if(SZ(max_matching())==n)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}