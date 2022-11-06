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
	ll n,m; cin>>n>>m;
	ll p[2][2]={0,0,0,0};
	ll l;
	fore(i,0,n){
		cin>>l; p[l%2][0]++;
	}
	fore(i,0,m){
		cin>>l; p[l%2][1]++;
	}
	cout<<min(p[0][0],p[1][1])+min(p[0][1],p[1][0]);
	return 0;
}