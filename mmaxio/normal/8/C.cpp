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
#include <cstdlib>
#include <cstdio>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int inf = 1000000000;

int n, x[24], y[24], d[24][24], d0[24], dp[1<<24], fr1[1<<24], fr2[1<<24], x0, y0;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d",&x0,&y0,&n); int m = 1<<n;
    REP(i,n) scanf("%d%d",&x[i],&y[i]);
    REP(i,n) REP(j,n) d[i][j] = sqr(x[i]-x[j])+sqr(y[i]-y[j]);
    REP(i,n) d0[i] = sqr(x[i]-x0)+sqr(y[i]-y0);
    REP(i,m) dp[i] = inf;
    dp[0] = 0; int to;
    REP(i,m) if (dp[i]!=inf) {
        REP(j,n) if (!(i&(1<<j))) {
            to = i|(1<<j);
            if (dp[to]>dp[i]+2*d0[j]) {
                dp[to] = dp[i]+2*d0[j];
                fr1[to] = j, fr2[to] = -1;
            };
            FORD(k,j+1,n-1) if (!(i&(1<<k))) {
                to = i|(1<<j)|(1<<k);
                if (dp[to]>dp[i]+d0[j]+d0[k]+d[j][k]) {
                    dp[to] = dp[i]+d[j][k]+d0[j]+d0[k];
                    fr1[to] = j, fr2[to] = k;
                }
            }
            break;
        }
    }

    //REP(i,n) cerr << d0[i] << ' '; cerr << '\n';
    //REP(i,m) cerr << dp[i] << ' '; cerr << '\n';
    //REP(i,m) cerr << fr1[i] << ' ' << fr2[i] << '\n';

    int cur = m-1;
    printf("%d\n",dp[m-1]);
    while (cur!=0) {
        printf("0 %d ",fr1[cur]+1);
        if (fr2[cur]!=-1) {
            printf("%d ",fr2[cur]+1);
            cur ^= (1 << fr1[cur]) | (1 << fr2[cur]);
        } else cur ^= (1 << fr1[cur]);
    }
    printf("0\n");
}