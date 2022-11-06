#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	vector< pair<ll,ll> > d;
	ll bue=0;
	fore(i,0,n){
		if(a[i]!=0){
			if(b[i]==0){
				d.pb({0,1});
			}else{
				ll g=__gcd(a[i],b[i]);
				a[i]/=g; b[i]/=g;
				if(b[i]<0){b[i]*=-1;a[i]*=-1;}
				d.pb({b[i]*(-1),a[i]});
			}
		}else{
			if(b[i]==0){
				bue++;
			}
		}
	}
	sort(ALL(d));
	ll tot=0,maxi=0;
	pair<ll,ll> va={0,2};
	fore(i,0,SZ(d)){
		if(d[i].fst==va.fst&&d[i].snd==va.snd){
			tot++;
		}else{va.fst=d[i].fst; va.snd=d[i].snd; tot=1;
		}
		maxi=max(maxi,tot);
	}
	cout<<maxi+bue;
	return 0;
}