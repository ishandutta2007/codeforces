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

int N,M;
vint G[111111];
vint rG[111111];
int deg[111111];
signed main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		rG[b].pb(a);
	}

	priority_queue<int>que;
	rep(i,N){
		deg[i]=G[i].size();
		if(deg[i]==0){
			que.push(i);
		}
	}


	vint ans(N);
	for(int i=N-1;i>=0;i--){
		int v=que.top();
		que.pop();
		ans[v]=i;
		for(auto u:rG[v]){
			if(--deg[u]==0)que.push(u);
		}
	}

	rep(i,N){
		if(i)printf(" ");
		printf("%lld",ans[i]+1);
	}
	puts("");
    return 0;
}