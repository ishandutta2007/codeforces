#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
typedef vector<int>vint;
typedef pair<int,int>pint;

struct UF{
    int N;
    vint par,val;
    void init(int n){
        N=n;
        par.resize(N);
        val.resize(N);
        rep(i,N)par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        par[y]=x;
        val[x]+=val[y];
    }
};

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int H,W,Q;
char fld[1111][1111];
signed main(){
    scanf("%d%d%d",&H,&W,&Q);
    UF uf;uf.init(H*W);
    rep(i,H)scanf("%s",fld[i]);
    rep(i,H)rep(j,W){
        if(fld[i][j]=='*')continue;
        rep(d,4){
            int ny=i+dy[d],nx=j+dx[d];
            if(ny<0||ny>=H||nx<0||nx>=W)continue;
            if(fld[ny][nx]=='.')uf.unite(i*W+j,ny*W+nx);
            else uf.val[uf.find(i*W+j)]++;
        }
    }
    while(Q--){
        int y,x;scanf("%d%d",&y,&x);y--;x--;
        printf("%d\n",uf.val[uf.find(y*W+x)]);
    }
    return 0;
}