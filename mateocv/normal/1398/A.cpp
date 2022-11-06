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
		pair<ll,ll> a[n];
		fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
		sort(a,a+n);
		if(a[0].fst+a[1].fst>a[n-1].fst){
			cout<<-1<<"\n";
		}else{
			vector<ll> res={a[0].snd,a[1].snd,a[n-1].snd};
			sort(ALL(res));
			for(auto i:res)cout<<i+1<<" "; cout<<"\n";
		}
		
	}
	
	return 0;
}