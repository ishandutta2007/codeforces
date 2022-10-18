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
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

const double EPS = 1e-7;
const int MAXITER = 65;

typedef long long ll;
typedef double lf;

vector<double> d;
int n, k, eps;
double minWinProb;
double dp[101];

double get(double d, double r) {
    return (d < r + EPS) ? 1 : exp(1 - sqr(d) / sqr(r));
}

bool check(double r) {
    
    //cerr << r << ' ';
    
    clean(dp);
    dp[0] = 1;
    
    REP(i, n) {
        double pr = get(d[i], r);
        //dp[k] = dp[k] * (1 - pr) + dp[k - 1] * pr;
        FORP(j, n, 1)
            dp[j] = dp[j] * (1 - pr) + dp[j - 1] * pr;
        dp[0] = dp[0] * (1 - pr);
    }

    double tmp = 0;

    FORD(i, k, n) tmp += dp[i];
    
    return tmp < minWinProb;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int x0, y0;
    scanf("%d%d%d%d%d", &n, &k, &eps, &x0, &y0);
    
    minWinProb = (1000 - eps) / 1000.0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d",&x, &y);
        d.pb(sqrt(1.0 * sqr(x - x0) + sqr(y - y0)));
    }
    sort(all(d));
    int tmp = 0;
    REP(i, n) if (fabs(d[i]) < EPS) tmp++;
    
    if (tmp >= k) {
        puts("0");
        return 0;
    }
    
    double l = 0, r = d.back();
    
    REP(iter, MAXITER) {
        double mid = (l + r) * .5;
        if (check(mid)) l = mid;
        else r = mid;
    }

    printf("%.12lf",l);
    
}