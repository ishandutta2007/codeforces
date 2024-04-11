
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef double D;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)(a).size())
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

const int N = 105;

bool used[N];

double mn, mx;

double prof[N];

int n, k;

int main() {
    mn = 1e9;
    mx = -1e9;

    scanf("%d %d", &n, &k);

    int cnt = k;

    k = n / k;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &prof[i]);
    }
    set<VI> vis;
    int q;
    scanf("%d", &q);
    while (q--) {
        double sum = 0;
        VI v;
        for (int j = 0; j < k; ++j) {
            int cr;
            scanf("%d", &cr);
            v.PB(cr);
            sum += prof[cr];
            used[cr] = true;
        }
        sort(ALL(v));
        vis.insert(v);
        mn = min(mn, sum / k);
        mx = max(mx, sum / k);
    }

    vector<double> v;

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            v.PB(prof[i]);
        }
    }

    sort(ALL(v));
    
    if ((int) vis.size() < cnt && (int) v.size() >= k) {
        {
            double sum = 0;
            for (int i = 0; i < k; ++i) {
                sum += v[i];
            }
            mn = min(mn, sum / k);
        }
        {
            double sum = 0;
            for (int i = (int) v.size() - k; i < (int) v.size(); ++i) {
                sum += v[i];
            }
            mx = max(mx, sum / k);
        }
    }

    printf("%.9lf %.9lf\n", mn, mx);

    return 0;
}