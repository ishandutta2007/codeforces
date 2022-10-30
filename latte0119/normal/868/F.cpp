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



int N,K;
int A[111111];

//Upper Triangular Matrix
namespace DCOptUTM{
using D=int;
const D INF=numeric_limits<D>::max()/10;
vector<D>dp,nex;


int cur_l,cur_r;


int cnt[111111];
int val=0;

inline D f(int l,int r){
	return val;
}

void ex_r(){
	//add
	val+=cnt[A[cur_r]];
	cnt[A[cur_r]]++;

	cur_r++;
}
void ex_l(){
    cur_l--;

	//add
	val+=cnt[A[cur_l]];
	cnt[A[cur_l]]++;
}

void sh_r(){
    cur_r--;
	//del
	cnt[A[cur_r]]--;
	val-=cnt[A[cur_r]];
}

void sh_l(){
	//del
	cnt[A[cur_l]]--;
	val-=cnt[A[cur_l]];

    cur_l++;
}

// nex : [l,r)    cand : [opt_l,opt_r]
void solve(int l,int r,int opt_l,int opt_r){
	if(l==r)return;
	int m=(l+r)/2;

	while(m>cur_r)ex_r();
	while(opt_l<cur_l)ex_l();
	while(m<cur_r)sh_r();
	while(opt_l>cur_l)sh_l();

	//cur_l==opt_l
	//cur_r==m

	pair<D,int>mi(INF,opt_l);
	while(cur_l<m&&cur_l<=opt_r){
		chmin(mi,pair<D,int>(dp[cur_l]+f(cur_l,cur_r),cur_l));
		sh_l();
	}
	nex[m]=mi.fi;
	if(l+1==r)return;
	solve(l,m,opt_l,mi.se);
	solve(m+1,r,mi.se,opt_r);
}

vector<D>convolute(const vector<D>&ini){
	dp=ini;
	nex.resize(ini.size());
	solve(0,dp.size(),0,dp.size());
	return nex;
}

vector<D>monotoneMinima(int N){
	return convolute(vector<D>(N+1,0));
}


//dp[k][i]=min{dp[k-1][j]+f(j,i)  | j<i};
vector<D>calcDP(int N,int K){
	vector<D>cur(N+1,INF);
	cur[0]=0;
	for(int k=0;k<K;k++){
		cur=convolute(cur);
	}
	return cur;
}

}
signed main(){
	scanf("%lld%lld",&N,&K);
	rep(i,N)scanf("%lld",&A[i]);
	auto dp=DCOptUTM::calcDP(N,K);
	cout<<dp[N]<<endl;
	return 0;
}