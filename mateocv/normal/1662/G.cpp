#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=1000006;

ll n; 

vector<ll> g[MAXN];

ll p[MAXN],c[MAXN],w[MAXN];

void dfs(ll x){
	for(auto i:g[x]){
		dfs(i);
		c[x]+=c[i];
		w[x]+=w[i];
	}
	c[x]++;
	w[x]+=c[x];
}

ll w2[MAXN];

void dfs2(ll x){
	vector<ll> sumpw{0};
	for(auto i:g[x]){
		sumpw.pb(sumpw.back()+w[i]);
	}
	ll pos=0;
	for(auto i:g[x]){
		w2[i]+=sumpw[pos]-sumpw[0];
		w2[i]+=sumpw[SZ(g[x])]-sumpw[pos+1];
		w2[i]+=w2[x];
		w2[i]+=n-c[i];
		pos++;
	}
	for(auto i:g[x])dfs2(i);
}

typedef bitset<1000000> bs;

ll solve(vector<ll> v){
	if(v.back()>=(n-1)/2)return v.back()*(n-1-v.back());
	vector<ll> oc(n);
	for(auto i:v)oc[i]++;
	fore(i,0,n){
		if(oc[i]>2){
			ll cant=(oc[i]-1)/2;
			oc[i]-=2*cant;
			oc[2*i]+=cant;
		}
	}
	bs vis;
	vis[0]=1;
	fore(i,0,n){
		while(oc[i]){
			vis=vis|(vis<<i);
			oc[i]--;
		}
	}
	ll res=0;
	fore(i,0,n){
		if(vis[i])res=max(res,(n-i-1)*i);		
	}
	//cout<<"solve\n";
	//for(auto i:v)cout<<i<<" ";
	//cout<<"-> "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1)cin>>p[i+1],p[i+1]--;
	fore(i,1,n)g[p[i]].pb(i);
	/*
	fore(i,0,n){
		for(auto j:g[i]){
			cout<<i<<" "<<j<<endl;
		}
	}
	*/
	dfs(0);
	dfs2(0);
	ll res=0;
	fore(i,0,n){
		//cout<<i<<":\n";
		ll val=n;
		//cout<<val<<"\n";
		for(auto j:g[i])val+=w[j];
		//cout<<val<<"\n";
		if(i)val+=w2[i];
		//cout<<val<<"\n";
		vector<ll> v;
		for(auto j:g[i])v.pb(c[j]);
		if(i)v.pb(n-c[i]);
		//cout<<i<<" "<<SZ(v)<<endl;
		sort(ALL(v));
		val+=solve(v);
		res=max(res,val);
	}
	cout<<res<<"\n";
	
	return 0;
}