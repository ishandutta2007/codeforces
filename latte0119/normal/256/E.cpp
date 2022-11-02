#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int mod=777777777;
int N,M;
int T[3][3];

const int SEG=1<<17;
int seg[SEG*2][3][3];

inline void update_node(int k){
    if(seg[k*2+2][0][0]==-1){
        rep(i,3)rep(j,3)seg[k][i][j]=seg[k*2+1][i][j];
        return;
    }
    rep(i,3)rep(j,3){
        seg[k][i][j]=0;
        rep(ii,3)rep(jj,3){
            if(!T[ii][jj])continue;
            seg[k][i][j]=(seg[k][i][j]+seg[k*2+1][i][ii]*seg[k*2+2][jj][j])%mod;
        }
    }
}
void init(){
    memset(seg,0,sizeof(seg));
    rep(i,N)rep(j,3)seg[i+SEG-1][j][j]=1;
    reps(i,N,SEG)seg[i+SEG-1][0][0]=-1;
    for(int i=SEG-2;i>=0;i--)update_node(i);
}
void update(int k,int t){
    k+=SEG-1;
    rep(i,3)rep(j,3)seg[k][i][j]=0;
    if(t==0){
        rep(i,3)seg[k][i][i]=1;
    }
    else seg[k][t-1][t-1]=1;
    while(k){
        k=(k-1)/2;
        update_node(k);
    }
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,3)rep(j,3)scanf("%lld",&T[i][j]);
    init();
    while(M--){
        int k,t;
        scanf("%lld%lld",&k,&t);
        update(k-1,t);
        int sum=0;
        rep(i,3)rep(j,3)sum+=seg[0][i][j];
        printf("%lld\n",sum%mod);
    }
    return 0;
}