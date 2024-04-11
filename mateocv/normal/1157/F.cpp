#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
ll a[200005];
int main(){FIN;
	ll n; cin>>n;
	ll le;
	fore(i,0,n){
		cin>>le;
		a[le]++;
	}
	vector<pair<ll,pair<ll,ll>>> v;
	ll tot=0,s=0;
	fore(i,0,200002){
		if(a[i]>=2){
			if(tot==0)s=i;
			tot+=a[i];
		}else if(a[i]==1){
			if(tot==0)s=i;
			tot++;
			v.pb({tot,{s,i}});
			s=i;
			tot=1;
		}else{
			if(tot>0)v.pb({tot,{s,i-1}});
			tot=0; s=i+1;
		}
	}
	sort(ALL(v));
	pair<ll,pair<ll,ll>> res=v.back();
	cout<<res.fst<<"\n";
	fore(i,res.snd.fst,res.snd.snd+1){
		cout<<i<<" "; a[i]--;
	}
	for(int i=res.snd.snd;i>=res.snd.fst;i--){
		while(a[i]){
			cout<<i<<" "; a[i]--;
		}
	}
	
	return 0;
}