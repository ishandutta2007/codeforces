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

ll vis[200006];

int main(){FIN;
	ll n,z; cin>>n>>z;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll res=0,l=0,r=(n+1)/2;
	while(r<n){
		if(a[r]-a[l]>=z){
			res++; l++; r++;
		}else r++;
	}
	cout<<res;
	return 0;
}