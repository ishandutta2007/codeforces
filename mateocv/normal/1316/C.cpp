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

int main(){FIN;
	ll n,m,p; cin>>n>>m>>p;
	ll a[n],b[m];
	fore(i,0,n)cin>>a[i],a[i]%=p;
	fore(i,0,m)cin>>b[i],b[i]%=p;
	ll l=0,r=0;
	while(1){
		assert(l<n&&r<m);
		if(a[l]==0){
			l++; continue;
		}
		if(b[r]==0){
			r++; continue;
		}
		cout<<l+r; break;
	}
	
	return 0;
}