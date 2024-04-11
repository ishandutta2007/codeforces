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


int N,Q;
int P[1111111];
int L[1111111],R[1111111];

int ans[1111111];

int nex[1111111];

void calc(){
    for(int i=N-1;i>=0;i--){
        nex[i]=i+1;
        while(nex[i]!=N&&P[i]>P[nex[i]])nex[i]=nex[nex[i]];
    }


    vector<vint>qs(N);
    rep(i,Q)qs[L[i]].pb(i);

    BinaryIndexedTree bit0(N+114),bit1(N+114);
    for(int i=N-1;i>=0;i--){
        bit0.add(i+1,-(i+1));
        bit1.add(i+1,1);
        bit0.add(nex[i],nex[i]);
        bit1.add(nex[i],-1);
        for(auto k:qs[i]){
            ans[k]+=bit1.sum(R[k])*R[k]+bit0.sum(R[k])-bit1.sum(L[k])*L[k]-bit0.sum(L[k]);
        }
    }
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    rep(i,N)scanf("%lld",&P[i]);
    rep(i,Q)scanf("%lld",&L[i]),L[i]--;
    rep(i,Q)scanf("%lld",&R[i]);

    calc();
    reverse(P,P+N);
    rep(i,Q){
        int l=N-R[i];
        int r=N-L[i];
        L[i]=l;R[i]=r;
    }
    calc();
    rep(i,Q)printf("%lld\n",ans[i]+R[i]-L[i]);
    return 0;
}