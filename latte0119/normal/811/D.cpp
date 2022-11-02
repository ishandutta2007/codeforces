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

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int k[]={0,0};

int H,W;
char fld[111][111];

int y,x;
string s="URDL";
inline void q(char c){
    cout<<c<<endl;
    cin>>y>>x;
    x--;y--;
    if(fld[y][x]=='F')exit(0);
}

int dist[111][111];

signed main(){
    cin>>H>>W;
    rep(i,H)cin>>fld[i];

    memset(k,-1,sizeof(k));
    if(W>1&&fld[0][1]!='*'){
        q('R');
        if(x==0){
            k[1]=2;
        }
        else{
            k[1]=0;
        }
        while(true){
            if(k[0]==-1&&H>1&&fld[y+1][x]!='*'){
                q('D');
                if(y==0){
                    k[0]=2;
                }
                else{
                    q('U');
                    k[0]=0;
                }
            }
            if(x+1==W||fld[y][x+1]=='*')break;
            q(s[1^k[1]]);
        }
        while(x)q(s[3^k[1]]);
    }
    if(k[0]==-1&&H>1&&fld[1][0]!='*'){
        q('D');
        if(y==0){
            k[0]=2;
        }
        else{
            k[0]=0;
        }
        while(true){
            if(k[1]==-1&&W>1&&fld[y][x+1]!='*'){
                q('R');
                if(x==0){
                    k[1]=2;
                }
                else{
                    q('L');
                    k[1]=0;
                }
            }
            if(y+1==H||fld[y+1][x]=='*')break;
            q(s[2^k[0]]);
        }
        while(y)q(s[0^k[0]]);
    }

    queue<pint>que;
    fill_n(*dist,111*111,INT_MAX);
    dist[0][0]=0;
    que.push({0,0});
    while(que.size()){
        int y,x;
        tie(y,x)=que.front();
        que.pop();
        rep(d,4){
            int ny=y+dy[d],nx=x+dx[d];
            if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='*')continue;
            if(dist[ny][nx]!=INT_MAX)continue;
            dist[ny][nx]=dist[y][x]+1;
            que.push({ny,nx});
        }
    }

    int sy,sx;
    rep(i,H)rep(j,W)if(fld[i][j]=='F')sy=i,sx=j;
    vint lis;
    while(sy||sx){
        rep(d,4){
            int ny=sy+dy[d];
            int nx=sx+dx[d];
            if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='*'||dist[ny][nx]+1!=dist[sy][sx])continue;
            lis.pb(d^2);
            sy=ny;
            sx=nx;
            break;
        }
    }

    reverse(all(lis));
    for(auto w:lis)q(s[w^k[w&1]]);
    return 0;
}