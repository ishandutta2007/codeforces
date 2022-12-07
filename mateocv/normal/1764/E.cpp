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
		ll as,bs; cin>>as>>bs;
		if(n==1){
			cout<<(k<=as?"YES\n":"NO\n");
			continue;
		}
		vector<pair<ll,ll>> a(n-1);
		fore(i,0,n-1)cin>>a[i].fst>>a[i].snd;
		if(k<=as){
			cout<<"YES\n";
			continue;
		}
		if(k>as+bs){
			cout<<"NO\n";
			continue;
		}
		fore(i,0,n-1)a[i].snd*=-1;
		sort(ALL(a));
		fore(i,0,n-1)a[i].snd*=-1;
		ll s=a[0].fst;
		fore(i,1,n-1){
			s=max(s,min(s,a[i].fst)+a[i].snd);
			s=max(s,a[i-1].fst+a[i-1].snd);
			s=max(s,a[i].fst);
		}
		//s=max(s,a[n-2].fst+a[n-2].snd);
		//cout<<"s "<<s<<"\n";
		if(s>=k-bs)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}