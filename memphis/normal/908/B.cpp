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

const int N=55;

int n,m,v[4],ls,sx,sy,cnt;
char s[N][N],ss[105];
bool bv[4];

int dfs2(int x,int y,int p){
    if(s[x][y]=='#') return 0;
    if(s[x][y]=='E')
        return 1; 
    if(p>ls) return 0;
    int vv=v[ss[p]];
    if(vv==0){
        // up
        if(x==1) return 0;
        return dfs2(x-1,y,p+1);
    }
    if(vv==1){
        // left
        if(y==1) return 0;
        return dfs2(x,y-1,p+1);
    }
    if(vv==2){
        // right
        if(y==m) return 0;
        return dfs2(x,y+1,p+1);
    }
    if(x==n) return 0;
    return dfs2(x+1,y,p+1);
}

void dfs1(int x){
    if(x>3){
        cnt+=dfs2(sx,sy,1);
        return;
    }
    rep(i,0,3)
        if(bv[i]==0){
            bv[i]=1;
            v[x]=i;
            dfs1(x+1);
            bv[i]=0;
        }
}


int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,1,n)
        rep(j,1,m){
            if(s[i][j]=='S'){
                sx=i;
                sy=j;
                s[i][j]='.';
            }
        }
    scanf("%s",ss+1);
    ls=strlen(ss+1);
    rep(i,1,ls) ss[i]-='0';
    dfs1(0);        
    printf("%d\n",cnt);
}