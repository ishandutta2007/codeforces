#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

LL n;

vector<LL> divisors;

vector<int> winner;

int main() {
    cin >> n;
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.PB(i);
            if (i * i < n) {
                divisors.PB(n / i);
            }
        }
    }
    sort(ALL(divisors));
    winner.resize(divisors.size());
    LL goodMove;
    for (int i = 0; i < (int) winner.size(); ++i) {
        goodMove = -1;
        winner[i] = 0;
        for (int j = 1; j < i; ++j) {
            if (divisors[i] % divisors[j] == 0) {
                if (winner[j] == 2) {
                    goodMove = divisors[j];
                    winner[i] = 1;
                } else if (winner[i] == 0) {
                    winner[i] = 2;
                }
            }
        }
        if (winner[i] == 0) {
            goodMove = 0;
            winner[i] = 1;
        }
    }
    if (goodMove == -1) {
        printf("2\n");
    } else {
        printf("1\n");
        cout << goodMove << endl;
    }

}