#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

struct UF{
    int N;
    vint par,sz;
    void init(int n){
        N=n;
        par.resize(N);
        sz.assign(N,1);
        rep(i,N)par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        par[y]=x;
        sz[x]+=sz[y];
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int get(int x){return sz[find(x)];}
};

UF uf;

int dxy[]={0,-1,0,1,0};

int H,W;
int fld[1000][1000];

signed main(){
    scanf("%d%d",&H,&W);
    rep(i,H)rep(j,W){
        char c;scanf(" %c",&c);
        if(c=='*')fld[i][j]=1;
    }

    uf.init(H*W);
    rep(i,H)rep(j,W){
        if(fld[i][j])continue;
        rep(d,4){
            int ny=i+dxy[d];
            int nx=j+dxy[d+1];
            if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx])continue;
            uf.unite(i*W+j,ny*W+nx);
        }
    }

    rep(i,H){
        rep(j,W){
            if(!fld[i][j]){
                printf(".");
                continue;
            }
            set<int>s;
            rep(d,4){
                int ny=i+dxy[d];
                int nx=j+dxy[d+1];
                if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx])continue;
               s.insert(uf.find(ny*W+nx));
            }

            int tmp=0;
            each(it,s){
                tmp+=uf.get(*it);
            }
            printf("%d",(tmp+1)%10);
        }
        puts("");
    }
    return 0;
}