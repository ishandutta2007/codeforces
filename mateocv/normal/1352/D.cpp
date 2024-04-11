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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res=0,tot[2]={0,0};
		deque<ll> d;
		fore(i,0,n)d.pb(a[i]);
		tot[0]=d.front();
		res++;
		ll va=d.front();
		d.pop_front();
		fore(i,1,n){
			ll sum=0;
			ll van=0;
			while(sum<=va&&SZ(d)){
				if(i%2==0){
					sum+=d.front();
					van+=d.front();
					d.pop_front();
				}else{
					sum+=d.back();
					van+=d.back();
					d.pop_back();
				}
			}
			if(SZ(d)==0){
				res++;
				tot[i%2]+=van;
				break;
			}
			if(sum>va){
				res++;
				tot[i%2]+=van;
				va=sum;
			}
			
		}
		cout<<res<<" "<<tot[0]<<" "<<tot[1]<<"\n";
	}
	
	
	return 0;
}