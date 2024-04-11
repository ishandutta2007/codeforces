#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int N,M;
int S,T;
int P[2222];

vpint G[2222];

vint calc(int s){
	vint dist(N,INF);
	dist[s]=0;
	priority_queue<pint,vector<pint>,greater<pint>>que;
	que.push(pint(0,s));
	while(que.size()){
		int c,v;
		tie(c,v)=que.top();
		que.pop();
		if(dist[v]<c)continue;
		for(auto &e:G[v]){
			if(e.se+c>=dist[e.fi])continue;
			dist[e.fi]=e.se+c;
			que.push(pint(dist[e.fi],e.fi));
		}
	}
	vint uku=dist;
	sort(all(uku));uku.erase(unique(all(uku)),uku.end());
	rep(i,N)dist[i]=lower_bound(all(uku),dist[i])-uku.begin();
	return dist;
}

int dp[2222][2222][2];

int cnt[2222][2222];
int sum[2222][2222];

int dfs(int a,int b,int p){
	int &ret=dp[a][b][p];
	if(ret!=INF)return ret;

	if(cnt[a][N]+cnt[N][b]-cnt[a][b]==N)return ret=0;
	if(p==0){
		ret=dfs(a+1,b,0);
		if(cnt[a+1][N]-cnt[a][N]-cnt[a+1][b]+cnt[a][b])chmax(ret,dfs(a+1,b,1));
		ret+=sum[a+1][N]-sum[a][N]-sum[a+1][b]+sum[a][b];
	}
	else{
		ret=dfs(a,b+1,1);
		if(cnt[N][b+1]-cnt[N][b]-cnt[a][b+1]+cnt[a][b])chmin(ret,dfs(a,b+1,0));
		ret-=sum[N][b+1]-sum[N][b]-sum[a][b+1]+sum[a][b];
	}
	return ret;
}

signed main(){

	scanf("%lld%lld",&N,&M);
	scanf("%lld%lld",&S,&T);S--;T--;
	rep(i,N)scanf("%lld",&P[i]);

	rep(i,M){
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		a--;b--;
		G[a].pb(pint(b,c));
		G[b].pb(pint(a,c));
	}

	vint dS=calc(S);
	vint dT=calc(T);
	rep(i,N){
		cnt[dS[i]+1][dT[i]+1]++;
		sum[dS[i]+1][dT[i]+1]+=P[i];
	}
	rep(i,N+1){
		rep(j,N+1){
			cnt[i+1][j]+=cnt[i][j];
			cnt[i][j+1]+=cnt[i][j];
			cnt[i+1][j+1]-=cnt[i][j];

			sum[i+1][j]+=sum[i][j];
			sum[i][j+1]+=sum[i][j];
			sum[i+1][j+1]-=sum[i][j];
		}
	}



	fill_n(**dp,2222*2222*2,INF);
	int tmp=dfs(0,0,0);
	if(tmp>0)cout<<"Break a heart"<<endl;
	else if(tmp<0)cout<<"Cry"<<endl;
	else cout<<"Flowers"<<endl;
	return 0;
}