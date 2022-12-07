#include<bits/stdc++.h>
#define maxn 2050

using namespace std;
char s[maxn];
int n,ans,dp[maxn][maxn],m,x,y,r,c;
int u[maxn*maxn*2],v[maxn*maxn*2],L,R;
bool f[maxn][maxn],g[maxn][maxn];

bool valid(int x,int y){
    if (x<0||x>=n||y<0||y>=m) return false;
    return f[x][y]&&!g[x][y];
}

int main(){
    cin >> n >> m >> r >> c >> x >> y;
    r--; c--;
    for (int i=0;i<n;i++){
        scanf("%s",s);
        for (int j=0;j<m;j++)
            f[i][j]=(s[j]=='.');
    }
    L=R=maxn*maxn; u[L]=r; v[L]=c; g[r][c]=true;
    while (L<=R){
        int X=u[L],Y=v[L],w=dp[X][Y]; L++;
        if (valid(X+1,Y)){
            u[--L]=X+1; v[L]=Y;
            g[X+1][Y]=true;
            dp[X+1][Y]=dp[X][Y];
        }
        if (valid(X-1,Y)){
            u[--L]=X-1; v[L]=Y;
            g[X-1][Y]=true;
            dp[X-1][Y]=dp[X][Y];
        }
        if (valid(X,Y+1)){
            u[++R]=X; v[R]=Y+1;
            g[X][Y+1]=true;
            dp[X][Y+1]=dp[X][Y]+1;
        }
        if (valid(X,Y-1)){
            u[++R]=X; v[R]=Y-1;
            g[X][Y-1]=true;
            dp[X][Y-1]=dp[X][Y]+1;
        }
    }
    int cnt=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            if (g[i][j]){
                int res=dp[i][j],U=(res+c-j)/2,V=(res+j-c)/2;
                if (U<=x&&V<=y) cnt++;
            }
        }
    cout << cnt << endl;
}