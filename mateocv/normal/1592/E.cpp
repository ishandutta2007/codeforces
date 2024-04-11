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

const int MAXN=(1ll<<20)+20;

ll INF=1e8;

pair<ll,ll> ran[MAXN];

void add(ll x, ll pos){
	ran[x].fst=min(ran[x].fst,pos);
	ran[x].snd=max(ran[x].snd,pos);
}

ll solve(vector<ll> v){
	vector<ll> vis;
	ll x=0;
	vis.pb(x);
	add(x,0);
	fore(i,0,SZ(v)){
		x^=v[i];
		vis.pb(x);
		add(x,i+1);
	}
	ll res=0;
	for(auto i:vis){
		res=max(res,ran[i].snd-ran[i].fst);
		ran[i].fst=INF,ran[i].snd=-INF;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll mk=0,res=0;
	fore(i,0,MAXN)ran[i].fst=INF,ran[i].snd=-INF;
	for(ll j=19;j>=0;j--){
		mk^=(1ll<<j);
		vector<ll> v;
		fore(i,0,n){
			if(a[i]&(1ll<<j))v.pb(a[i]&mk);
			else{
				res=max(res,solve(v));
				v.clear();
			}
		}
		res=max(res,solve(v));
	}
	cout<<res<<"\n";
	
	return 0;
}