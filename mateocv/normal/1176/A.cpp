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
		ll n; cin>>n;
		ll res=0;
		while(n%2==0||n%3==0||n%5==0){
			if(n%2==0){
				res++; n/=2; continue;
			}
			if(n%3==0){
				res+=2; n/=3; continue;
			}
			if(n%5==0){
				res+=3; n/=5; continue;
			}
		}
		if(n==1)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}