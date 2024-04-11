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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		pair<pair<ll,ll>,ll> seg[n];
		fore(i,0,n){
			cin>>seg[i].fst.fst>>seg[i].fst.snd;
			seg[i].snd=i;
		}
		sort(seg,seg+n);
		ll l=seg[0].fst.fst, r=seg[0].fst.snd, res[n],tot=0;
		fore(i,0,n){
			if(seg[i].fst.fst<=r){
				r=max(seg[i].fst.snd,r);
				res[seg[i].snd]=1;
			}else{
				res[seg[i].snd]=2;
				tot++;
			}
		}
		if(tot){
			fore(i,0,n){
				cout<<res[i]<<" ";
			}
		}else{
			cout<<"-1";
		}
		cout<<"\n";
	}
	
	return 0;
}