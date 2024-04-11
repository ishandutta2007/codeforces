#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF= 1LL<<52;
const int MAXN = 2e5+9;
const int MAXR = 22;
const int MAXT = 360;

int dx[4]={1,-1,0,0};//0..20
int dy[4]={0,0,1,-1};//0..360
// cells are [r-1, r] [t1, t1+1]
int mv[MAXR][MAXT][4];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n; cin >> n;
        for(int i=0;i<MAXR;i++){
            for(int j=0;j<MAXT;j++){
                for(int k=0;k<4;k++){
                    mv[i][j][k]=0;//no blocking!
                }
            }
        }
        for(int i=0;i<n;i++){
            char c; cin >> c;
            if(c=='C'){
                int r,t1,t2;cin >> r >> t1 >> t2;
                if(t1<t2){
                    for(int j=t1;j<t2;j++)mv[r][j][0]=1;
                    for(int j=t1;j<t2;j++)mv[r+1][j][1]=1;
                }
                else{
                    for(int j=t1;j<t2+MAXT;j++)mv[r][j%MAXT][0]=1;
                    for(int j=t1;j<t2+MAXT;j++)mv[r+1][j%MAXT][1]=1;
                }
            }
            else{
                int r1 ,r2,t;cin >> r1 >> r2 >> t;
                for(int j=r1+1;j<=r2;j++)mv[j][(t+MAXT-1)%MAXT][2]=1;
                for(int j=r1+1;j<=r2;j++)mv[j][t][3]=1;
            }
        }
        bool vis[MAXR][MAXT]={};
        queue<pii> q;
        vis[MAXR-1][0]=1;
        q.push({MAXR-1,0});
        bool win = 0;
        while(q.size()){
            pii cur = q.front();q.pop();
            int x = cur.F, y = cur.S;
            if(x==0){
                win= 1;break;
            }
            //cout << x << ' ' << y << endl;
            for(int d=0;d<4;d++){
                if(mv[x][y][d])continue;
                int nx = x+dx[d], ny = (y+dy[d]+MAXT)%MAXT;
                if(nx>=MAXR||vis[nx][ny])continue;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
        if(win)cout << "YES" << endl;
        else cout << "NO" << endl;
        //cout << (win ? "YES" :"NO") << endl;
    }
}