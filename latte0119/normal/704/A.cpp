#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct BIT{
    vint dat;
    int N;
    void init(int n){
        N=n;
        dat.resize(N+1);
    }
    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

int N,Q;
vint lis[300000];

signed main(){
    scanf("%lld%lld",&N,&Q);
    BIT bit;bit.init(Q+114);

    int n=0;

    int ma=0;
    rep(i,Q){
        int t,x;
        scanf("%lld%lld",&t,&x);
        if(t==1){
            x--;
            lis[x].pb(n);
            bit.add(n,1);
            n++;
        }
        else if(t==2){
            x--;
            for(auto v:lis[x]){
                if(bit.sum(v)-bit.sum(v-1)==1){
                    bit.add(v,-1);
                }
            }
            lis[x]=vint();
        }
        else{
            for(;ma<x;ma++){
                if(bit.sum(ma)-bit.sum(ma-1)==1){
                    bit.add(ma,-1);
                }
            }
        }
        printf("%lld\n",bit.sum(Q));
    }
    return 0;
}