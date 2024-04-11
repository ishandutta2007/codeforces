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
		ll n,k; cin>>n>>k;
		if(k>(n-1)/2){
			cout<<"-1\n";
		}else{
			vector<ll> res(n);
			fore(i,0,n)res[i]=-1;
			fore(i,0,k)res[2*i+1]=i+1;
			ll ul=k+1;
			fore(i,0,n){
				if(res[i]==-1)res[i]=ul,ul++;
			}
			fore(i,0,n)cout<<n-res[i]+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}