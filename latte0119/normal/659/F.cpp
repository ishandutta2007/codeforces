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

struct UF{
    int N;
    vint par,sz;
    void init(int n){
        N=n;
        par.resize(N);
        sz.resize(N);
        rep(i,N)par[i]=i,sz[i]=1;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[y]>sz[x])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    int getsz(int x){
        return sz[find(x)];
    }
};

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int H,W,K;
int A[1111][1111];
int visited[1111][1111];
void dfs(int y,int x,int s,int &k){
    if(k==0)return;
    visited[y][x]=1;
    k--;
    rep(i,4){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||ny>=H||nx<0||nx>=W||A[ny][nx]<s||visited[ny][nx])continue;
        dfs(ny,nx,s,k);
    }
}

vint ord[1000000];

signed main(){
    scanf("%lld%lld%lld",&H,&W,&K);
    vint press;
    rep(i,H)rep(j,W){
        scanf("%lld",&A[i][j]);
        press.pb(A[i][j]);
    }
    sort(all(press));
    rep(i,H)rep(j,W){
        A[i][j]=lower_bound(all(press),A[i][j])-press.begin();
        ord[A[i][j]].pb(i*W+j);
    }
    UF uf;uf.init(H*W);

    for(int i=press.size()-1;i>=0;i--){
        rep(j,ord[i].size()){
            int y=ord[i][j]/W,x=ord[i][j]%W;
            rep(d,4){
                int ny=y+dy[d],nx=x+dx[d];
                if(ny<0||ny>=H||nx<0||nx>=W||A[ny][nx]<A[y][x])continue;
                uf.unite(ny*W+nx,ord[i][j]);
            }
        }
        if(K%press[i])continue;
        int tmp=K/press[i];
        rep(j,ord[i].size()){
            if(uf.getsz(ord[i][j])>=tmp){
                int y=ord[i][j]/W,x=ord[i][j]%W;
                puts("YES");
                dfs(y,x,i,tmp);
                rep(ii,H){
                    rep(jj,W){
                        if(visited[ii][jj])printf("%lld ",press[i]);
                        else printf("0 ");
                    }puts("");
                }
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}