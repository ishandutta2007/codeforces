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

const int N = 555;

char img[N][N];
int u[N][N], l[N][N];

int getSum(int a[N][N], int r, int c) {
    if (r < 0 || c < 0) {
        return 0;
    }
    return a[r][c];
}

int getSum(int a[N][N], int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) {
        return 0;
    }
    --r1; --c1;
    int res = getSum(a, r2, c2)
                - getSum(a, r2, c1)
                - getSum(a, r1, c2)
                + getSum(a, r1, c1);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    REP(i, n) {
        scanf("%s", img[i]);
    }
    REP(i, n) REP(j, m) {
        if (i - 1 >= 0 && img[i][j] == '.' && img[i - 1][j] == '.') {
            u[i][j] = 1;
        }
        if (j - 1 >= 0 && img[i][j] == '.' && img[i][j - 1] == '.') {
            l[i][j] = 1;
        }
    }
    REP(i, n) REP(j, m) {
        if (i) {
            u[i][j] += u[i - 1][j];
            l[i][j] += l[i - 1][j];
        }
        if (j) {
            u[i][j] += u[i][j - 1];
            l[i][j] += l[i][j - 1];
        }
        if (i && j) {
            u[i][j] -= u[i - 1][j - 1];
            l[i][j] -= l[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        --r1; --c1; --r2; --c2;
        int ans = getSum(l, r1, c1 + 1, r2, c2);
        ans += getSum(u, r1 + 1, c1, r2, c2);
        printf("%d\n", ans);
    }
    return 0;
}