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
	pair<ll,ll> a[n];
	fore(i,0,n){
		cin>>a[i].fst;
		a[i].snd=i;
	}
	sort(a,a+n);
	vector<pair<ll,ll>> v;
	ll sum=0;
	fore(i,0,k*m){
		v.pb(a[n-1-i]);
		swap(v[i].fst,v[i].snd);
		sum+=v[i].snd;
	}
	cout<<sum<<"\n";
	sort(v.begin(),v.end());
	fore(i,1,k){
		cout<<v[i*m-1].fst+1<<" ";
	}
	
	return 0;
}