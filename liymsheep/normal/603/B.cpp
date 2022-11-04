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

const double eps = 1e-12;

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

const int N = 1000007;

const int MOD = 1000000007;

LL frac(int x) {
    LL result = 1;
    for (int i = 1; i <= x; ++i) {
        result = result * i % MOD;
    }
    return result;
}

LL power(LL x, int y) {
    LL result = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
    }
    return result;
}

bool vis[N];

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << power(n, n - 1) << endl;
        return 0;
    }
    if (k == 1) {
        cout << power(n, n) << endl;
        return 0;
    }
    VI cycles;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }

        int sz = 0;
        LL j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = j * k % n;
            ++sz;
        }

        cycles.push_back(sz);
    }

    LL ans = 1;

    map<int, int> index;
    SORT(cycles);
    for (int i = 0; i < cycles.size(); ) {
        int j = i;
        while (j < cycles.size() && cycles[i] == cycles[j]) {
            ++j;
        }
        int num = j - i;
        index[cycles[i]] = num;
        // cout << "c: " << cycles[i] << ", num: " << num << endl;

        LL delta = 0;
        TR(it, index) {
            if (cycles[i] % it->first == 0) {
                delta = (delta + it->first * it->second) % MOD;
            }
        }

        ans = ans * power(delta, num) % MOD;

        i = j;
    }
    cout << ans << endl;
    return 0;
}