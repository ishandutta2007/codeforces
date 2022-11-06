#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m,h; cin>>n>>h>>m;
	ll l[m],r[m],x[m];
	fore(i,0,m)cin>>l[i]>>r[i]>>x[i];
	ll maxi[n];
	fore(i,0,n)maxi[i]=h;
	fore(i,0,m){
		fore(j,1,n+1){
			if(l[i]<=j&&j<=r[i]){
				maxi[j-1]=min(maxi[j-1],x[i]);
			}
		}
	}
	ll res=0;
	fore(i,0,n)res+=maxi[i]*maxi[i];
	cout<<res;
	return 0;
}