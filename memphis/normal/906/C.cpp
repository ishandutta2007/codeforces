#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <bitset>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N=23;

int n,m,ans,tmp[N][N],tt,av;


void dfs(int S,int las,int d){
    if(d>=ans) return;
    bool flag=1;
    rep(i,1,n)  if(tmp[d][i]!=tt){
        flag=0;
        break;
    }
    if(flag){
        ans=d;
        av=S;
        return;
    }
    rep(i,las,n){
        int vv=1<<i;
        if(!(S&vv)){
            rep(j,1,n) tmp[d+1][j]=tmp[d][j];
            rep(j,1,n)
                if(tmp[d+1][j]&vv)
                    tmp[d+1][j]|=tmp[d+1][i];
            dfs(S|vv,i+1,d+1);
        }
    }
}


int main(){
    scanf("%d%d",&n,&m);
    ans=n;
    rep(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        tmp[0][x]|=1<<y;
        tmp[0][y]|=1<<x;
    }
    rep(i,1,n) tt|=1<<i;
    av=tt;
    rep(i,1,n) tmp[0][i]|=1<<i;
    dfs(0,1,0); 
    printf("%d\n",ans);
    rep(i,1,n) if((1<<i)&av) printf("%d ",i);
    puts("");
}