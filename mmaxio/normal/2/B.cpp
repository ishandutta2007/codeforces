#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int inf = 1001000;

int d[2][1000][1000];
int dp[2][1000][1000];
string ans;
int n;

void getAns(int x, int y) {
    printf("1\n");
    REP(i,x) pch('D');REP(i,y) pch('R');
    REP(i,n-1-x) pch('D');REP(i,n-1-y) pch('R');
    exit(0);
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x;

    bool can_one = 0;
    int null_x, null_y;

    scanf("%d\n",&n);
    clean(d);
    REP(i,n) {
        REP(j,n) {
            scanf("%d",&x);
            if (x==0) {
                can_one = 1;
                null_x = i, null_y = j;
                d[0][i][j] = d[1][i][j] = inf;
            } else {
                while (x % 2 == 0) d[0][i][j]++, x/=2;
                while (x % 5 == 0) d[1][i][j]++, x/=5;
            }
        }
    }

    REP(w,2) {
    
        dp[w][0][0] = d[w][0][0];
        REP(i,n) REP(j,n) if(i+j!=0) {
            dp[w][i][j] = inf;
            if (i!=0) dp[w][i][j] = min(dp[w][i-1][j]+d[w][i][j],dp[w][i][j]);
            if (j!=0) dp[w][i][j] = min(dp[w][i][j-1]+d[w][i][j],dp[w][i][j]);
        }

    }

    int w;

    if (dp[0][n-1][n-1]<dp[1][n-1][n-1]) w = 0; else w = 1;

    if (can_one && dp[w][n-1][n-1]>=1) getAns(null_x,null_y);
    
    printf("%d\n",dp[w][n-1][n-1]);
    int cx = n-1, cy = n-1;
    while (cx+cy != 0) {
        if (cx!=0 && dp[w][cx-1][cy] + d[w][cx][cy] == dp[w][cx][cy]) ans.pb('D'),cx--; else ans.pb('R'),cy--;
    }

    FORP(i,sz(ans)-1,0) pch(ans[i]);

}