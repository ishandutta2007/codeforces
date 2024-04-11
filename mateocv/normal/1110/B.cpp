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

int main(){FIN;
	
	ll n,m,k; cin>>n>>m>>k;
	ll dist[n-1],a,b,lon=1;
	cin>>a;
	fore(i,0,n-1){
		cin>>b;
		dist[i]=b-a-1;
		lon+=dist[i]+1;
//		cout<<dist[i]<<" ";
		a=b;
	}
//	cout<<lon<<" ";
	sort(dist,dist+(n-1));
	fore(i,0,k-1){
		lon-=dist[n-2-i];
	}
	cout<<lon;
	
	return 0;
}