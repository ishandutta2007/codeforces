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

ll a[1010];

bool cmp(pair<ll,ll> i, pair<ll,ll> j){
	return a[i.fst]<a[j.fst];
}

vector<ll> g[1010];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	set<ll> st;
	fore(i,0,n)st.insert(a[i]);
	map<ll,ll> mp;
	ll va=0;
	for(auto i:st)mp[i]=va++;
	fore(i,0,n)a[i]=mp[a[i]];
	fore(i,0,n)g[a[i]].pb(i);
	va=0;
	fore(i,0,1010){
		for(auto j:g[i]){
			a[j]=va++;
		}
	}
	vector<pair<ll,ll>> mov[n];
	vector<pair<ll,ll>> res;
	fore(i,0,n){
		fore(j,i+1,n){
			if(a[i]>a[j])mov[j].pb({i,j});
		}
	}
	for(ll i=n-1;i>=0;i--){
		if(SZ(mov[i])==0)continue;
		sort(ALL(mov[i]),cmp);
		for(auto j:mov[i])swap(a[j.fst],a[j.snd]);
	}
	fore(i,0,n){
		for(auto j:mov[n-1-i])res.pb(j);
	}
/*	for(auto i:res){
		swap(a[i.fst],a[i.snd]);
		//fore(j,0,n)cout<<a[j]<<" "; cout<<"\n";
	}*/
	fore(i,0,n-1){
		if(a[i]>a[i+1]){
			cout<<-1;
			return 0;
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	
	return 0;
}