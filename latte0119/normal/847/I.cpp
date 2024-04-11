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

int H,W,Q,P;
char fld[333][333];

int sum[333][333];

const int INF=1001001001;

int dist[333][333];

int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};

signed main(){
    cin>>H>>W>>Q>>P;
    rep(i,H)cin>>fld[i];

    fill_n(*dist,333*333,INF);
    rep(i,H){
        rep(j,W){
            if(!isalpha(fld[i][j]))continue;
            int n=(fld[i][j]-'A'+1)*Q;

            vpint que;
            dist[i][j]=0;
            que.pb({i,j});
            sum[i][j]+=n;
            for(int k=0;k<que.size();k++){
                int y,x;
                tie(y,x)=que[k];
                if(dist[y][x]==30)continue;

                rep(d,4){
                    int ny=y+dy[d],nx=x+dx[d];
                    if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='*')continue;
                    if(dist[ny][nx]!=INF)continue;
                    dist[ny][nx]=dist[y][x]+1;
                    sum[ny][nx]+=n/(1ll<<dist[ny][nx]);
                    que.pb({ny,nx});
                }
            }

            rep(k,que.size())dist[que[k].fi][que[k].se]=INF;
        }
    }

    int cnt=0;
    rep(i,H)rep(j,W)if(sum[i][j]>P)cnt++;
    cout<<cnt<<endl;
    return 0;
}