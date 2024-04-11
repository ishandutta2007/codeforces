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
	ll n,v; cin>>n>>v;
	ll res=0,fin=1,cap=0;
/*	while(fin<n){
		ll dif=min(n-fin,v);
		res+=dif*fin;
		fin+=dif;
	}*/
	res+=min(n-1,v);cap+=res;
	while(cap<n-1){
		fin++;
		cap++;
		res+=fin;
	}
	
	cout<<res;
	
	return 0;
}