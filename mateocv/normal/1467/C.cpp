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

ll INF=9e18;

int main(){FIN;
	ll n[3];
	fore(i,0,3)cin>>n[i];
	vector<ll> v[3];
	ll sum[3],mini[3]={INF,INF,INF};
	mset(sum,0);
	fore(k,0,3){
		v[k].resize(n[k]);
		fore(i,0,n[k])cin>>v[k][i];
		sort(ALL(v[k]));
		for(auto i:v[k])sum[k]+=i,mini[k]=min(mini[k],i);
	}
	ll res=-INF;
	ll s=sum[0]+sum[1]+sum[2];
	fore(i,0,3)res=max(res,s-2ll*mini[i]-2ll*mini[(i+1)%3]);
	fore(i,0,3)res=max(res,s-2ll*sum[i]);
	cout<<res<<"\n";
	
	return 0;
}