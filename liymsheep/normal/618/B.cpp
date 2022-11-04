#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>
#include <unordered_map>

using namespace std;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

const int N = 55;

int a[N][N], ans[N], times[N];
bool used[N];

int main() {
    int n;
    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];
    FILL(ans, -1);
    REP(i, n - 2) {
        CLEAR(times);
        REP(u, n) REP(v, n) if (!used[u] && !used[v] && a[u][v] == i + 1) {
            ++times[u];
        }
        REP(u, n) if (times[u] > 1) {
            used[u] = true;
            ans[u] = i + 1;
        }
    }
    int res = n - 2;
    REP(i, n) {
        if (ans[i] == -1) {
            ans[i] = ++res;
        }
    }

    REP(i, n) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << endl;
    return 0;
}