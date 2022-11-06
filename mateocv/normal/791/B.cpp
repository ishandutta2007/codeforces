#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll n;
vector<ll> g0[150002];
ll vis[150002];
ll vec[150002];
map<ll,ll> g1;
//ll g1[150000][150000];
ll check(ll x){
	for(auto i:g0[x]){
		if(vis[i]||vec[x]!=vec[i])return 0;
		for(auto j:g0[x]){
			if(g1.count(i*n+j)==0&&i!=j)return 0;
		}
	}	
	return 1;
}

int main(){FIN;
	ll m;cin>>n>>m;
	ll a,b;
	//memset(g1,0,sizeof g1);
	memset(vis,0,sizeof vis);
	memset(vec,0,sizeof vis);
	fore(i,0,m){
		cin>>a>>b;
		g1[(a-1)*n+b-1]=1;
		g1[(b-1)*n+a-1]=1;
		g0[a-1].pb(b-1);
		g0[b-1].pb(a-1);
		vec[a-1]++; vec[b-1]++;
	}
	ll va=0,minvis=0;
	while(va<n){
		if(check(minvis)){
			for(auto i:g0[minvis]){
				vis[i]++; va++;
			}
			vis[minvis]++; va++;
		}else{
			cout<<"NO"; return 0;
		}
		fore(i,minvis+1,n){
			if(vis[i]==0){
				minvis=i; break;
			}
			
		}
		
		
	}
	cout<<"YES";	
	
	
	return 0;
}