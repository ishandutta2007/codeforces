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

const int MODULO = 1000000007;

const int N = 200007;

VI edge[N];

LL cover[N * 8];
LL prodSum[N * 8], prod[N * 8];
LL at[N];

int inTime[N], outTime[N];
int timeStamp = 0;

int value[N];

void dfs(int x, int fa) {
    inTime[x] = timeStamp++;
    TR(it, edge[x]) {
        if (*it == fa) {
            continue;
        }
        dfs(*it, x);
    }
    outTime[x] = timeStamp - 1;
}

void build(int left, int right, int x) {
    cover[x] = 1;
    prodSum[x] = prod[x] = 0;
    if (left < right) {
        int mid = (left + right) >> 1;
        build(left, mid, x * 2);
        build(mid + 1, right, x * 2 + 1);
    }
}

inline void mult(int x, LL delta) {
    cover[x] = cover[x] * delta % MODULO;
    prod[x] = prod[x] * delta % MODULO;
    prodSum[x] = prodSum[x] * delta % MODULO;
}

inline void pushDown(int x) {
    if (cover[x] != 1) {
        mult(x * 2, cover[x]);
        mult(x * 2 + 1, cover[x]);
        cover[x] = 1;
    }
}

inline void pushUp(int x) {
    prod[x] = (prod[x * 2] + prod[x * 2 + 1]);
    if (prod[x] >= MODULO) prod[x] -= MODULO;
    prodSum[x] = (prodSum[x * 2] + prodSum[x * 2 + 1]);
    if (prodSum[x] >= MODULO) prodSum[x] -= MODULO;
}

void change(int left, int right, int l, int r, int x, LL delta) {
    if (l <= left && r >= right) {
        mult(x, delta);
        return;
    }
    pushDown(x);
    int mid = (left + right) >> 1;
    if (l <= mid) change(left, mid, l, r, x * 2, delta);
    if (r > mid) change(mid + 1, right, l, r, x * 2 + 1, delta);
    pushUp(x);
}

void changeAt(int left, int right, int at, int x, LL val, LL key = 1) {
    if (left == right) {
        prod[x] = key;
        prodSum[x] = val * key % MODULO;
        return;
    }
    pushDown(x);
    int mid = (left + right) >> 1;
    if (at <= mid) {
        changeAt(left, mid, at, x * 2, val, key);
    } else {
        changeAt(mid + 1, right, at, x * 2 + 1, val, key);
    }
    pushUp(x);
}

LL getProd(int left, int right, int l, int r, int x) {
    if (l <= left && r >= right) {
        return prod[x];
    }
    pushDown(x);
    int mid = (left + right) >> 1;
    LL res = 0;
    if (l <= mid) res += getProd(left, mid, l, r, x * 2);
    if (r > mid) res += getProd(mid + 1, right, l, r, x * 2 + 1);
    if (res >= MODULO) res -= MODULO;
    return res;
}

LL getProdSum(int left, int right, int l, int r, int x) {
    if (l <= left && r >= right) {
        return prodSum[x];
    }
    pushDown(x);
    int mid = (left + right) >> 1;
    LL res = 0;
    if (l <= mid) res += getProdSum(left, mid, l, r, x * 2);
    if (r > mid) res += getProdSum(mid + 1, right, l, r, x * 2 + 1);
    if (res >= MODULO) res -= MODULO;
    return res;
}

LL powMod(LL x, int y) {
    LL z = 1;
    for (; y; y >>= 1) {
        if (y & 1) z = z * x % MODULO;
        x = x * x % MODULO;
    }
    return z;
}

LL inv(LL x) {
    return powMod(x, MODULO - 2);
}

int degree[N], parent[N];
int p0[N], p1[N], p2[N], lab[N];

int main() {
    int q;
    cin >> value[0] >> q;
    parent[0] = -1;
    int n = 1;
    REP(i, q) {
        scanf("%d%d", &p0[i], &p1[i]);
        if (p0[i] == 1) {
            scanf("%d", &p2[i]);
        }

        int type = p0[i];
        if (type == 1) {
            int pi = p1[i] - 1;
            int vi = p2[i];
            edge[pi].PB(n);
            parent[n] = pi;
            lab[i] = n;
            value[n++] = vi;
        } else {
        }
    }
    dfs(0, -1);
    build(0, n - 1, 1);
    changeAt(0, n - 1, inTime[0], 1, value[0]);
    REP(i, q) {
        int type = p0[i];
        if (type == 1) {
            int node = lab[i];
            int pi = parent[node];
            int vi = value[node];
            ++degree[pi];
            change(0, n - 1, inTime[pi], outTime[pi], 1, inv(degree[pi]) * (degree[pi] + 1) % MODULO);
            LL key = getProd(0, n - 1, inTime[pi], inTime[pi], 1);
            // cout << "key for " << node << " is " << key << ", inTime is " << inTime[pi] << endl;
            changeAt(0, n - 1, inTime[node], 1, vi, key);
        } else {
            int ui = p1[i] - 1;
            LL coef = 1;
            if (parent[ui] != -1) {
                int p = parent[ui];
                coef = inv(getProd(0, n - 1, inTime[p], inTime[p], 1));
            }
            LL result = getProdSum(0, n - 1, inTime[ui], outTime[ui], 1);
            result = result * coef % MODULO;
            result = (result + MODULO) % MODULO;
            cout << result << endl;
        }
        // REP(j, n) {
        //     cout << "prod for " << j << " is " << getProdSum(0, n - 1, inTime[j], inTime[j], 1) << endl;
        // }
    }
    return 0;
}