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
	ll n; cin>>n;
	pair<ll,ll> a[n];
	memset(a,-1,sizeof a);
	ll llega;
	fore(i,0,2*n){
		cin>>llega; llega--;
		if(a[llega].fst==-1){
			a[llega].fst=i;
		}else{
			a[llega].snd=i;
		}
	}
	ll res=0;
	fore(i,0,n){
		if(i==0){
			res+=a[0].fst+a[0].snd;
		}else{
			res+=min(abs(a[i-1].fst-a[i].fst)+abs(a[i-1].snd-a[i].snd),abs(a[i-1].fst-a[i].snd)+abs(a[i-1].snd-a[i].fst));
		}
	}
	cout<<res;
	return 0;
}