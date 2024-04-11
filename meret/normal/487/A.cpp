
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

int main() {
    int hp_y, atk_y, def_y;
    int hp_m, atk_m, def_m;
    int h, a, d;
    cin >> hp_y >> atk_y >> def_y;
    cin >> hp_m >> atk_m >> def_m;
    cin >> h >> a >> d;

    // hp_y > x * (atk_m - def_y)
    // hp_m <= x * (atk_y - def_m)
    
    int result = (int) 1e9;
    
    for (int da = 0; da <= 200; ++da) {
        if (atk_y + da <= def_m) {
            continue;
        }
        for (int dd = 0; dd <= atk_m; ++dd) {
            int y = hp_y;
            int m = hp_m;
            while (m > 0) {
                m -= atk_y + da - def_m;
                y -= atk_m - dd - def_y;
            }
            int dh = max(0, 1 - y);
            result = min(result, da * a + dd * d + dh * h);
        }
    }
    cout << result << endl;

}