#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

const int INF=1001001001001001001ll;

int N,M;
int X[5555];
int acc[5555];
signed main(){
	scanf("%lld%lld",&N,&M);
	rep(i,N)scanf("%lld",&X[i]);
	sort(X,X+N);

	vpint hs;
	rep(i,M){
		int p,c;
		scanf("%lld%lld",&p,&c);
		hs.eb(p,c);
	}
	sort(all(hs));

	vint dp(N+1,INF);
	vint nex(N+1);
	dp[0]=0;

	for(auto &ukuchang:hs){
		int p,c;
		tie(p,c)=ukuchang;
		for(int i=0;i<N;i++)acc[i+1]=acc[i]+abs(X[i]-p);
		deque<pint>deq;
		fill(all(nex),INF);
		nex[0]=0;
		deq.eb(0,0);
		for(int i=0;i<N;i++){
			if(i+1-deq.front().se>c)deq.pop_front();
			while(deq.size()&&deq.front().fi>=dp[i+1]-acc[i+1])deq.pop_back();
			deq.eb(dp[i+1]-acc[i+1],i+1);
			chmin(nex[i+1],deq.front().fi+acc[i+1]);
		}
		swap(dp,nex);
	}
	if(dp[N]==INF)cout<<-1<<endl;
	else cout<<dp[N]<<endl;
	return 0;
}