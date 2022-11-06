#include <bits/stdc++.h>
#define pb push_back
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
	ll q; cin>>q;
	while(q--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		string RGB="RGB";
		ll a[n][3];
		fore(j,0,3){
			fore(i,0,n){
				a[i][j]=(s[i]==RGB[(i+j)%3]);
			}
		}
		ll res=0;
		fore(j,0,3){
			ll sum=0;
			fore(i,0,k)sum+=a[i][j];
			res=max(res,sum);
			fore(i,k,n){
				sum+=a[i][j];
				sum-=a[i-k][j];
				res=max(res,sum);
			}
		}
		cout<<k-res<<"\n";
	}
	
	return 0;
}