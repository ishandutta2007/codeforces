#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const int MAXN=1e5+10;
vector<ii> g[MAXN];
ll mxp[MAXN], bst2[MAXN], pth[MAXN], sum[MAXN],ans[MAXN],totsum;

ii oper(ii a, ii b){
	if(a.fst>=b.fst) return {a.fst, max(a.snd,b.fst)};
	return {b.fst, max(b.snd,a.fst)};
}

ii oper(ii a, ll x){
	if(x>=a.fst) return {x,a.fst};
	return {a.fst, max(a.snd,x)};
}

void dfs(int pos, int p=-1){
	ii acum2={0,0};
	
	fore(i,0,SZ(g[pos])) if(g[pos][i].fst==p){
		g[pos].erase(g[pos].begin()+i);
		break;
	}
	
	for(auto x:g[pos]){
		dfs(x.fst,pos);
		
		ll now=x.snd+mxp[x.fst];
		acum2=oper(acum2,now);
		
		mxp[pos]=max(mxp[pos], now);
		sum[pos]+=sum[x.fst]+x.snd;
		pth[pos]=max(pth[pos], pth[x.fst]);
	}
	
	bst2[pos]=acum2.fst+acum2.snd;
	pth[pos]=max(pth[pos], bst2[pos]);
}

//respuesta es 2*(suma de aristas)-maximo

int db=0;

void go(int pos, ll mxup=0, ll bstup=0){
	if(SZ(g[pos])==0)return;
	vector<ll> lefpth={0},rigpth;
	vector<ii> lefmxp={{0,0}},rigmxp;
	
	//de izq a der
	{
		ii pingo={0,0};
		ll mx=0;
		fore(i,0,SZ(g[pos])){
			auto x=g[pos][i];
			mx=max(mx, pth[x.fst]);
			pingo=oper(pingo,x.snd+mxp[x.fst]);
			lefmxp.pb(pingo);
			lefpth.pb(mx);
		}
	}
	
	//de der a izq
	{
		ii pingo={0,0};
		ll mx=0;
		for(int i=SZ(g[pos])-1;i>=0;i--){
			auto x=g[pos][i];
			mx=max(mx, pth[x.fst]);
			pingo=oper(pingo,x.snd+mxp[x.fst]);
			rigmxp.pb(pingo);
			rigpth.pb(mx);
		}
		reverse(ALL(rigpth));
		reverse(ALL(rigmxp));

		rigmxp.pb({0,0});
		rigpth.pb(0);
	}
	
	
	//borro de pos a x
	fore(i,0,SZ(g[pos])){
		auto x=g[pos][i];
		
		//mejor camino entero en un nodo
		ll pingo=max({lefpth[i], rigpth[i+1], bstup});
		
		//combinar caminos
		ii asd=oper(oper(lefmxp[i], rigmxp[i+1]), mxup);
		pingo=max(pingo, asd.fst+asd.snd);
		
		ll he=2ll*sum[x.fst]-pth[x.fst];
		ll me=2ll*(totsum-sum[x.fst]-x.snd) - pingo;
		
		ans[x.fst]=me+he;
		
		
		//recursion
		ll tomxup = asd.fst + x.snd;
		ll tobstup = max({lefpth[i], rigpth[i+1], bstup, asd.fst+asd.snd});
		
		go(x.fst, tomxup, tobstup);
		
	}
}

ll culo=1e18;

void doit(int pos, ll mxup=0){
	if(!SZ(g[pos]))return;
	
	vector<ll> v={mxup};
	for(auto x:g[pos]) v.pb(mxp[x.fst]+x.snd);
	
	sort(ALL(v));
	
	ll me=0;
	fore(i,0,min(SZ(v),4)) me+=v[SZ(v)-i-1];

	culo=min(culo,2*totsum-me);
	
	for(auto x:g[pos]){
		ll bst=v.back()==mxp[x.fst]+x.snd ? v[SZ(v)-2] : v[SZ(v)-1];
		
		doit(x.fst, bst+x.snd);
	}
	
	
}


int main(){FIN;
	int n; cin>>n;
	fore(i,1,n){
		int x,y,w; cin>>x>>y>>w; x--; y--;
		g[x].pb({y,w}); g[y].pb({x,w});
		totsum+=w;
	}

	if(n==1){
		cout<<"0\n";
		exit(0);
	}
	
	dfs(0);
	go(0);
	doit(0);
	
	ll res=1e18;
	fore(i,1,n) res=min(res, ans[i]);
	res=min(res,culo);
	
	cout<<res<<"\n";
}