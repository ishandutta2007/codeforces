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

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    inline int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    inline int size(int x){
        return sz[find(x)];
    }
};

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};

int N,K;
char fld[555][555];

int acc[555][555];

int cnt[555*555];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%s",fld[i]);

    UnionFindTree uf(N*N);
    rep(i,N){
        rep(j,N){
            if(fld[i][j]=='X'){
                acc[i+1][j+1]++;
            }
            else{
                rep(k,4){
                    int ny=i+dy[k],nx=j+dx[k];
                    if(ny<0||ny>=N||nx<0||nx>=N||fld[ny][nx]=='X')continue;
                    uf.unite(i*N+j,ny*N+nx);
                }
            }
        }
    }

    rep(i,N)rep(j,N)acc[i+1][j+1]+=acc[i][j+1]+acc[i+1][j]-acc[i][j];

    int ma=0;
    for(int i=0;i+K<=N;i++){
        memset(cnt,0,sizeof(cnt));
        int sum=0;
        rep(y,K)rep(x,K){
            if(fld[i+y][x]=='X')continue;
            if(cnt[uf.find((i+y)*N+x)]++==0)sum+=uf.size((i+y)*N+x);
        }

        rep(w,2){
            int y;
            if(w==0)y=i-1;
            else y=i+K;
            if(y<0||y>=N)continue;
            rep(x,K-1){
                if(fld[y][x]=='X')continue;
                if(cnt[uf.find(y*N+x)]++==0)sum+=uf.size(y*N+x);
            }
        }

        for(int j=0;j+K<=N;j++){
            if(j+K<N)rep(y,K){
                if(fld[i+y][j+K]=='X')continue;
                if(cnt[uf.find((i+y)*N+j+K)]++==0)sum+=uf.size((i+y)*N+j+K);
            }

            rep(w,2){
                int y;
                if(w==0)y=i-1;
                else y=i+K;
                int x=j+K-1;
                if(y<0||y>=N||x<0||x>=N||fld[y][x]=='X')continue;
                if(cnt[uf.find(y*N+x)]++==0)sum+=uf.size(y*N+x);
            }

            chmax(ma,sum+acc[i+K][j+K]-acc[i][j+K]-acc[i+K][j]+acc[i][j]);

            if(j!=0)rep(y,K){
                if(fld[i+y][j-1]=='X')continue;
                if(--cnt[uf.find((i+y)*N+j-1)]==0)sum-=uf.size((i+y)*N+j-1);
            }

            rep(w,2){
                int y;
                if(w==0)y=i-1;
                else y=i+K;
                int x=j;
                if(y<0||y>=N||x<0||x>=N||fld[y][x]=='X')continue;
                if(--cnt[uf.find(y*N+x)]==0)sum-=uf.size(y*N+x);
            }
        }
    }
    cout<<ma<<endl;
    return 0;
}