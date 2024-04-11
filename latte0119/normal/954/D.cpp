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
const int INF=1001001001;
int N;
vint G[1111];
vint calc(int s){
	vint dist(N,INF);
	dist[s]=0;

	queue<int>que;
	que.push(s);
	while(que.size()){
		int v=que.front();
		que.pop();

		for(auto u:G[v]){
			if(dist[u]!=INF)continue;
			dist[u]=dist[v]+1;
			que.push(u);
		}
	}
	return dist;
}

signed main(){
	int s,t;
	int M;
	cin>>N>>M>>s>>t;
	s--;t--;
	rep(i,M){
		int a,b;cin>>a>>b;a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	vint distS=calc(s);
	vint distT=calc(t);
	int ans=-M;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(min(distS[i]+distT[j],distS[j]+distT[i])+1<distS[t])continue;
			ans++;
		}
	}	
	cout<<ans<<endl;
	return 0;
}