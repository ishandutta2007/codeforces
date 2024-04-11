
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, Q;

const int N_ = 200500;
int team_[N_];

int team(int x) { return team_[x] == x ? x : (team_[x] = team(team_[x])); }
bool merge(int x, int y) {
    x = team(x);
    y = team(y);
    if (x == y) return false;
    team_[x] = y;
    return true;
}

set<int> S;

const int LEAF = 131072 * 2;
int tree[N_ + LEAF];

int get(int x) {
    int ret = 0;
    x += LEAF;
    while (x > 0) {
        ret = max(ret, tree[x]);
        x >>= 1;
    }
    return ret;
}

void upd(int x, int y, int v) {
    x += LEAF; y += LEAF;
    while (x <= y) {
        if ((x & 1) == 1) tree[x] = max(tree[x], v);
        if ((y & 1) == 0) tree[y] = max(tree[y], v);
        x = (x + 1) >> 1;
        y = (y - 1) >> 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("566D.in", "r", stdin);
    freopen("566D.out", "w", stdout);
#endif

    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) team_[i] = i, S.insert(i), upd(i, i, i);

    while (Q--) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            merge(x, y);
        }
        else if (t == 2) {
            for (int i = x; i <= y; ) {
                int j = get(i) + 1;
                if (j > y) {
                    upd(x, y, max(y, j - 1));
                    break;
                }
                merge(x, j);
                i = j;
            }
        }
        else if (t == 3) {
            puts(team(x) == team(y) ? "YES" : "NO");
        }
    }
    return 0;
}