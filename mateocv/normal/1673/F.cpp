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

ll stom(string s, ll b){
	reverse(ALL(s));
	ll res=0;
	fore(i,0,SZ(s)){
		res=4*res;
		if(s[i]=='1')res+=b+1;
	}
	return res;
}

vector<string> gc(ll n){
	if(n==0)return {""};
	auto g=gc(n-1);
	vector<string> res;
	for(auto i:g)res.pb(i+"0");
	reverse(ALL(g));
	for(auto i:g)res.pb(i+"1");
	return res;
}

const int MAXN=40;

ll val[MAXN][MAXN];

pair<ll,ll> ub[4096];

int main(){FIN;
	auto g=gc(5);
	/*
	for(auto i:g)cout<<i<<"\n";
	vector<ll> c(5);
	for(auto i:g){
		fore(j,0,SZ(i)){
			if(i[j]=='1')c[j]++;
		}
	}
	for(auto i:c)cout<<i<<" ";
	cout<<"\n";
	return 0;
	*/
	vector<ll> g0,g1;
	for(auto i:g)g0.pb(stom(i,0));
	for(auto i:g)g1.pb(stom(i,1));
	ll n,k; cin>>n>>k;
	assert(SZ(g)>=n);
	fore(i,0,n){
		fore(j,0,n){
			val[i][j]=(g0[i]^g1[j]);
			ub[val[i][j]]={i,j};
		}
	}
	ll s=0;
	fore(i,0,n){
		fore(j,0,n-1){
			cout<<(val[i][j]^val[i][j+1])<<" ";
			s+=(val[i][j]^val[i][j+1]);
		}
		cout<<"\n";
	}
	fore(i,0,n-1){
		fore(j,0,n){
			cout<<(val[i][j]^val[i+1][j])<<" ";
			s+=(val[i][j]^val[i+1][j]);
		}
		cout<<"\n";
	}
	cout<<endl;
	//cout<<s<<endl;
	assert(s<=48000);
	ll x=0;
	while(k--){
		ll y; cin>>y;
		x^=y;
		auto res=ub[x];
		cout<<res.fst+1<<" "<<res.snd+1<<endl;
	}
	
	return 0;
}