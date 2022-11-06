#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,d,m; cin>>n>>d>>m;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	vector<ll> v[2];
	fore(i,0,n)v[a[i]>m].pb(a[i]);
	fore(k,0,2)reverse(ALL(v[k]));
	ll sump[SZ(v[1])+1];
	sump[0]=0;
	fore(i,0,SZ(v[1]))sump[i+1]=sump[i]+v[1][i];
	ll res=0,sum=0;
	fore(i,0,SZ(v[0])+1){
		if(i>0)sum+=v[0][i-1];
		res=max(res,sum+sump[min((n-i+d)/(d+1),SZ(v[1]))]);
	}
	cout<<res<<"\n";
	return 0;
}