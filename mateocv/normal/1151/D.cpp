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
	ll n; cin>>n;
	ll a[2][n];
	fore(i,0,n)cin>>a[0][i]>>a[1][i];
	pair<ll,ll> p[n];
	fore(i,0,n){
		p[i].snd=i;
		p[i].fst=a[1][i]-a[0][i];
	}
	sort(p,p+n);
	//fore(i,0,n)cout<<p[i].snd+1<<" ";
	ll res=0;
	fore(i,1,n+1){
		res+=a[0][p[i-1].snd]*(i-1)+a[1][p[i-1].snd]*(n-i);
	}
	cout<<res;
	
	return 0;
}