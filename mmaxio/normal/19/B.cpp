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
#include <cstring>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const ll inf = 1000000000000000ll;

int c, t, n;
ll dp[2000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    FORD(i,1,n) dp[i] = inf; dp[0] = 0;
    REP(i,n) {
        scanf("%d%d",&t,&c); t++;
        FORP(j,n,0) {
            int tmp = min(j+t,n);
            dp[tmp] = min(dp[tmp],dp[j]+c);
        }
    }
    printf("%I64d",dp[n]);
}