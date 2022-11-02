#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

const int SIZE=400000,ST=1<<19;

int dat[ST*2],lazy[ST*2];
void init(){memset(lazy,-1,sizeof(lazy));}
void evaluate(int k){
    if(~lazy[k]){
        dat[k]=1LL<<lazy[k];
        if(k<ST-1){
            lazy[k*2+1]=lazy[k];
            lazy[k*2+2]=lazy[k];
        }
        lazy[k]=-1;
    }
}

void add(int a,int b,int x,int k=0,int l=0,int r=ST){
    evaluate(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        lazy[k]=x;
        evaluate(k);
        return;
    }
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
    dat[k]=dat[k*2+1]|dat[k*2+2];
}

int get(int a,int b,int k=0,int l=0,int r=ST){
    evaluate(k);
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return dat[k];
    return get(a,b,k*2+1,l,(l+r)/2)|get(a,b,k*2+2,(l+r)/2,r);
}


int N,Q;
int C[SIZE];
vint G[SIZE];

int tin[SIZE],tout[SIZE];
void dfs(int v,int p,int &k){
    tin[v]=k++;
    rep(i,G[v].size()){
        int to=G[v][i];
        if(to==p)continue;
        dfs(to,v,k);
    }
    tout[v]=k;
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    rep(i,N)scanf("%lld",&C[i]),C[i]--;

    rep(i,N-1){
        int a,b;scanf("%lld%lld",&a,&b);a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    int K=0;
    dfs(0,-1,K);

    rep(i,N)add(tin[i],tin[i]+1,C[i]);

    while(Q--){
        int type,v;
        scanf("%lld%lld",&type,&v);v--;
        if(type==1){
            int c;scanf("%lld",&c);c--;
            add(tin[v],tout[v],c);
        }
        else{
            int b=get(tin[v],tout[v]);
            int ans=0;
            rep(i,60)if(b>>i&1)ans++;
            printf("%lld\n",ans);
        }
    }
    return 0;
}