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

struct BinaryIndexedTree{
	int n;
	vector<int>dat;
	BinaryIndexedTree(int n=0):n(n){
		dat.resize(n+1);
	}
	void add(int k,int x){
		for(k++;k<=n;k+=k&-k)dat[k]+=x;
	}
	int sum(int k){
		int ret=0;
		for(k++;k;k-=k&-k)ret+=dat[k];
		return ret;
	}
};

int N,K;
int T[222222];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N){
        scanf("%lld",&T[i]);
        T[i]-=i+1;
        chmax(T[i],0ll);
    }

    vpint lis;
    rep(i,N)lis.pb({T[i],i});
    sort(all(lis));

    BinaryIndexedTree bit(222222);
    int ans=0;
    for(auto &w:lis){
        bit.add(w.se,1);
        if(w.fi>=K)continue;
        int r=K-w.fi-1;
        if(r>N)r=N;
        chmax(ans,bit.sum(r-1));
    }

    cout<<ans<<endl;
    return 0;
}