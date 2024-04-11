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

const ll MOD=998244353;

ll dist(pair<ll,ll> a, pair<ll,ll> b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}

const int MAXN=104;

ll d[MAXN][MAXN];

vector<ll> mult(vector<ll> a, vector<ll> b){
	vector<ll> res(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a)){
		fore(j,0,SZ(b)){
			res[i+j]=(res[i+j]+a[i]*b[j])%MOD;
		}
	}
	return res;
}

bool valid(vector<ll> v, vector<ll> vc){
	/*
	cout<<"val\n";
	for(auto j:v)cout<<j<<" ";
	cout<<"\n";
	for(auto j:vc)cout<<j<<" ";
	cout<<"\n";
	*/
	if(SZ(v)<=1)return 1;
	ll d0=d[v[0]][v[1]];
	fore(i,0,SZ(v)){
		fore(j,0,i){
			if(d[v[i]][v[j]]!=d0)return 0;
		}
	}
	fore(i,0,SZ(v)){
		fore(j,0,SZ(vc)){
			if(d[v[i]][vc[j]]<=d0)return 0;
		}
	}
	return 1;
}

ll fact[MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> v(n);
	fore(i,0,n)cin>>v[i].fst>>v[i].snd;
	vector<ll> mini(n,1e18);
	fore(i,0,n){
		fore(j,0,n){
			d[i][j]=dist(v[i],v[j]);
			if(i!=j)mini[i]=min(mini[i],d[i][j]);
		}
	}
	vector<vector<ll>> vv;
	vector<ll> vis(n);
	fore(i,0,n){
		if(vis[i])continue;
		vector<ll> u={i},uc;
		fore(j,0,n){
			if(i==j)continue;
			if(d[i][j]==mini[i])u.pb(j);
			else uc.pb(j);
		}
		if(valid(u,uc)){
			vv.pb(u);
			for(auto i:u)vis[i]=1;
		}else{
			vv.pb({i});
			vis[i]=1;
		}
	}
	/*
	for(auto i:vv){
		for(auto j:i)cout<<j<<" ";
		cout<<"\n";
	}
	*/
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	vector<ll> p={1};
	for(auto i:vv){
		vector<ll> q(SZ(i)+1);
		q[1]=1; q[SZ(i)]=1;
		p=mult(p,q);
		//for(auto j:q)cout<<j<<" ";
		//cout<<"\n";
	}
	//for(auto j:p)cout<<j<<" ";
	//cout<<"\n";
	ll res=0;
	fore(i,0,SZ(p)){
		ll val=fact[n]*fpow(fact[n-i],MOD-2)%MOD;
		res=(res+p[i]*val)%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}