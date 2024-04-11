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
int N,Q;
char S[222222];
vector<int>idx[10];
int sum[10][222222];

struct node{
    int val[8];
    node(){
        rep(i,8)val[i]=INF;
        val[0]=0;
    }
};

node calc(node b,node c){
    node a;
    for(int i=0;i<8;i++){
        chmin(a.val[i],b.val[i]);
        chmin(a.val[i],c.val[i]);
    }
    if(b.val[4]!=INF&&c.val[2]!=INF)chmin(a.val[6],b.val[4]+c.val[2]);
    if(b.val[4]!=INF&&c.val[3]!=INF)chmin(a.val[7],b.val[4]+c.val[3]);
    if(b.val[2]!=INF&&c.val[1]!=INF)chmin(a.val[3],b.val[2]+c.val[1]);
    if(b.val[6]!=INF&&c.val[1]!=INF)chmin(a.val[7],b.val[6]+c.val[1]);
    return a;
}

const int SEG=1<<18;
node dat[SEG*2];

node query(int a,int b,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return node();
    if(a<=l&&r<=b)return dat[k];
    return calc(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    scanf("%s",S);
    rep(i,N)idx[S[i]-'0'].pb(i);
    rep(i,N)sum[S[i]-'0'][i+1]++;
    rep(i,10)rep(j,N)sum[i][j+1]+=sum[i][j];

    for(int i=0;i<N;i++){
        if(S[i]=='2'){
            dat[SEG-1+i].val[4]=sum[2][i]-sum[0][i];
        }
        else if(S[i]=='0'){
            dat[SEG-1+i].val[2]=sum[0][i]-sum[1][i];
        }
        else if(S[i]=='1'){
            dat[SEG-1+i].val[1]=sum[1][i]-sum[6][i];
        }
    }

    for(int i=SEG-2;i>=0;i--)dat[i]=calc(dat[i*2+1],dat[i*2+2]);

    while(Q--){
        int l,r;
        scanf("%lld%lld",&l,&r);
        l--;
        int t=lower_bound(all(idx[7]),r)-idx[7].begin();
        t--;
        if(t==-1){
            puts("-1");
            continue;
        }
        t=idx[7][t];
        if(l>=t){
            puts("-1");
            continue;
        }
        node a=query(l,t);
        if(a.val[7]==INF)puts("-1");
        else printf("%lld\n",a.val[7]-sum[2][l]+sum[6][r]);
    }
    return 0;
}