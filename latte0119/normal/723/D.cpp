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

int H,W,K;
char fld[55][55];

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};

bool vis[55][55];
int dfs(int y,int x){
    vis[y][x]=true;
    int ret=1;
    rep(i,4){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=H||nx<0||nx>=W)continue;
        if(fld[ny][nx]=='*')continue;
        if(vis[ny][nx])continue;
        ret+=dfs(ny,nx);
    }

    if(y==0||y+1==H||x==0||x+1==W)return INT_MAX;
    return ret;
}

void col(int y,int x){
    fld[y][x]='*';
    rep(i,4){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='*')continue;
        col(ny,nx);
    }
}

signed main(){
    cin>>H>>W>>K;
    rep(i,H)cin>>fld[i];

    vpint lis;
    rep(i,H){
        rep(j,W){
            if(fld[i][j]=='*'||vis[i][j])continue;
            int tmp=dfs(i,j);
            if(tmp<INT_MAX)lis.pb(pint(tmp,i*W+j));
        }
    }

    sort(all(lis));
    reverse(all(lis));
    int ans=0;
    for(int i=K;i<lis.size();i++){
        col(lis[i].se/W,lis[i].se%W);
        ans+=lis[i].fi;
    }
    cout<<ans<<endl;
    rep(i,H)cout<<fld[i]<<endl;
}