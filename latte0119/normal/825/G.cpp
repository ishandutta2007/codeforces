#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}




int N,Q;


int last;
int dec(int x){
	return (x+last)%N+1;
}

vint G[1111111];

int L[1111111];

void dfs(int v,int p,int val){
	L[v]=val;
	for(auto u:G[v])if(u!=p)dfs(u,v,min(val,u));
}

signed main(){
	scanf("%lld%lld",&N,&Q);
	rep(i,N-1){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	int t,x;
	scanf("%lld%lld",&t,&x);
	x=dec(x)-1;

	

	dfs(x,-1,x);
	Q--;
	int tot=1001001001;
	while(Q--){
		scanf("%lld%lld",&t,&x);
		x=dec(x);
		x--;
		if(t==1){
			chmin(tot,L[x]);
		}
		else{
			int ans=min(tot,L[x])+1;
			last=ans;
			printf("%lld\n",ans);
		}
	}
    return 0;
}