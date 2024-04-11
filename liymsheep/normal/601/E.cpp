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

const int N = 33000;
const int M = 1007;

vector<PII> ev[N * 4];

void insert(int left, int right, int l, int r, int x, PII v) {
    // if (x == 1) cout << "L is " << l << " R is " << r << ", " << v.first << endl;
    if (l <= left && r >= right) {
        ev[x].PB(v);
        return;
    }
    int mid = (left + right) >> 1;
    if (l <= mid) {
        insert(left, mid, l, r, x * 2, v);
    }
    if (r > mid) {
        insert(mid + 1, right, l, r, x * 2 + 1, v);
    }
}

int dp[M];
int rec[30][M];

vector<int> query[N];

int k;

const int p = 10000000 + 19;
const int q = 1000000007;

int ans[N];

void go(PII x) {
    for (int i = k; i >= x.first; --i) {
        dp[i] = max(dp[i], dp[i - x.first] + x.second);
    }

}

void dfs(int left, int right, int x, int level) {
    REP(i, k + 1) rec[level][i] = dp[i];
    TR(it, ev[x]) {
        go(*it);
    }
    if (left != right) {
        int mid = (left + right) >> 1;
        dfs(left, mid, x * 2, level + 1);
        dfs(mid + 1, right, x * 2 + 1, level + 1);
    } else {
        TR(it, query[left]) {
        LL coef = 1;
        int hashes = 0;
        for (int i = 1; i <= k; ++i) {
            hashes = (hashes + dp[i] * coef) % q;
            coef = coef * p % q;
        }
            cout << hashes << endl;
        }
    }
    REP(i, k + 1) dp[i] = rec[level][i];
}

int main(){
    int n, q;
    cin >> n >> k;
    vector<PII> g(n);
    REP(i, n) {
        scanf("%d%d", &g[i].second, &g[i].first);
    }
    vector<int> when(n);
    fill(ALL(when), 0);
    cin >> q;
    REP(i, q) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int v, w;
            scanf("%d%d", &v, &w);
            when.PB(i + 1);
            g.PB(MP(w, v));
        } else if (tp == 2) {
            int which;
            scanf("%d", &which);
            --which;
            insert(0, q, when[which], i + 1, 1, g[which]);
            when[which] = -1;
        } else if (tp == 3) {
            query[i + 1].PB(i);
        }
    }
    REP(i, when.size()) {
        if (when[i] != -1) {
            insert(0, q, when[i], q, 1, g[i]);
        }
    }
    dfs(0, q, 1, 0);
    return 0;
}