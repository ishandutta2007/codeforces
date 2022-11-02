
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

int N,K;
int A[111111];

int sum[111111];

vint lis;

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

bool C(int x){
    BinaryIndexedTree bit(N+114);

    int cnt=0;
    rep(i,N){
        int w=lower_bound(all(lis),sum[i])-lis.begin();
        bit.add(w,1);

        int s=sum[i+1]-x;

        w=upper_bound(all(lis),s)-lis.begin();
        cnt+=bit.sum(w-1);
    }

    return cnt>=K;
}

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&A[i]),sum[i+1]=sum[i]+A[i];

    rep(i,N)lis.pb(sum[i]);
    sort(all(lis));lis.erase(unique(all(lis)),lis.end());

    int lb=-INF;
    int ub=INF;

    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid))lb=mid;
        else ub=mid;
    }
    cout<<lb<<endl;
    return 0;
}