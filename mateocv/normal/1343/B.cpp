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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if((n/2)&1){
			cout<<"NO\n";
		}else{
			ll res[n];
			ll sum=0;
			fore(i,0,n/2)res[i]=2*(i+1),sum+=2*(i+1);
			fore(i,0,n/2-1){
				res[n/2+i]=2*i+1;
				sum-=2*i+1;
			}
			res[n-1]=sum;
			cout<<"YES\n";
			fore(i,0,n)cout<<res[i]<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}