#include<bits/stdc++.h>
using namespace std;

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
signed A[4010][4010];
signed W[4010][4010];
namespace DCOpt{
using D=int;
const D INF=numeric_limits<D>::max()/10;
vector<D>dp,nex;

D weight(int l,int r){
    return W[l][r];
}

void solve(int l,int r,int opt_l,int opt_r){
	if(l==r)return;
	int m=(l+r)/2;

	pair<D,int>mi(INF,opt_l);
    for(int i=opt_l;i<m&&i<=opt_r;i++){
        chmin(mi,pair<D,int>(dp[i]+weight(i,m),i));
    }
	nex[m]=mi.fi;
	if(l+1==r)return;
	solve(l,m,opt_l,mi.se);
	solve(m+1,r,mi.se,opt_r);
}

vector<D>calc(){
	dp=vector<D>(N+1,INF);
	dp[0]=0;

	for(int k=1;k<=K;k++){
		nex=vector<D>(N+1,INF);
		solve(1,N+1,0,N-1);
		swap(dp,nex);
	}
	return dp;
}
}

signed main(){
    scanf("%d%d",&N,&K);
    getchar();
    rep(i,N)rep(j,N){
        char c=getchar();
        getchar();
        A[i][j]=c-'0';
    }

    rep(i,N){
        for(int j=1;j<=i;j++)A[i][j]+=A[i][j-1];
    }

    rep(i,N){
        for(int j=i+1;j<=N;j++){
            W[i][j]=W[i][j-1]+A[j-1][j-1]-(i?A[j-1][i-1]:0);
        }
    }

    auto v=DCOpt::calc();
    cout<<v[N]<<endl;
    return 0;
}