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
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;

int N;
int S[111111],M[111111],R[111111];

static const int SEG=1<<17;
vint ts[SEG*2],ms[SEG*2],rs[SEG*2];
int pre[SEG*2];

void init(int l,int r,int k){
    ms[k].pb(0);
    rs[k].pb(0);

    vector<tuple<int,int,int>>vec;
    for(int i=l;i<r&&i<N;i++){
        if(R[i]==0)vec.pb(make_tuple(INF,M[i],R[i]));
        else vec.pb(make_tuple(M[i]/R[i],M[i],R[i]));
    }
    sort(all(vec));
    for(auto w:vec){
        ts[k].pb(get<0>(w));
        ms[k].pb(ms[k].back()+get<1>(w));
        rs[k].pb(rs[k].back()+get<2>(w));
    }
    ts[k].pb(INF);

    if(r-l!=1){
        init(l,(l+r)/2,k*2+1);
        init((l+r)/2,r,k*2+2);
    }
}

int query(int a,int b,int t,int k=0,int l=0,int r=SEG){
    if(k<SEG-1&&pre[k]!=-1){
        pre[k*2+1]=pre[k];
        pre[k*2+2]=pre[k];
    }
    if(r<=a||b<=l)return 0;

    if(l+1==r&&pre[k]==0){
        pre[k]=t;
        return min(M[l],S[l]+t*R[l]);
    }
    if(a<=l&&r<=b){
        if(pre[k]==-1||pre[k]==0){
            pre[k]=t;
            return query(a,b,t,k*2+1,l,(l+r)/2)+query(a,b,t,k*2+2,(l+r)/2,r);
        }
        int w=lower_bound(all(ts[k]),t-pre[k])-ts[k].begin();
        int tmp=ms[k][w]+(rs[k].back()-rs[k][w])*(t-pre[k]);
        pre[k]=t;
        return tmp;
    }

    pre[k]=-1;
    return query(a,b,t,k*2+1,l,(l+r)/2)+query(a,b,t,k*2+2,(l+r)/2,r);
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld%lld%lld",&S[i],&M[i],&R[i]);

    init(0,SEG,0);

    int Q;scanf("%lld",&Q);
    while(Q--){
        int t,l,r;
        scanf("%lld%lld%lld",&t,&l,&r);
        l--;
        printf("%lld\n",query(l,r,t));
    }
    return 0;
}