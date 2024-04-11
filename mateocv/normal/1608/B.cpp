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
		ll n,a,b; cin>>n>>a>>b;
		if(abs(a-b)>1){
			cout<<"-1\n";
			continue;
		}
		ll sw=0;
		if(b>a)swap(a,b),sw++;
		ll ao=a,bo=b;
		ll l=0,r=n-1;
		vector<ll> res={l};
		l++;
		while(1){
			if(a){
				res.pb(r); r--;
				a--;
			}else if(!b){
				while(l<=r)res.pb(l),l++;
				break;
			}
			if(b){
				res.pb(l); l++;
				b--;
			}else if(!a){
				while(l<=r)res.pb(r),r--;
				break;
			}
		}
		ll c[2]={0,0};
		fore(i,1,n-1){
			if(res[i]>res[i-1]&&res[i]>res[i+1])c[0]++;
			if(res[i]<res[i-1]&&res[i]<res[i+1])c[1]++;
		}
		if(c[0]!=ao||c[1]!=bo){
			//cout<<c[0]<<" "<<c[1]<<"\n";
			cout<<"-1\n";
			continue;
		}
		if(sw){
			fore(i,0,n)res[i]=n-1-res[i];
		}
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}