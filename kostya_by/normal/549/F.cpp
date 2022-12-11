#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 300300;
const int MAXK = 1000100;

int n, k;
int a[MAXN];
long long answer;
int pref[MAXN];
int suff[MAXN];

pair<int, int> tree1[4 * MAXN];

bool flag = false;

vector<int> positions[MAXK];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first || (a.first == b.first && flag) ) {
        return a;
    }
    return b;
}

void init1(int v, int l, int r) {
    if (l == r) {
        tree1[v] = make_pair(a[l], l);
        return;
    }

    int x = (l + r) / 2;
    init1(v + v, l, x);
    init1(v + v + 1, x + 1, r);

    tree1[v] = combine(tree1[v + v], tree1[v + v + 1] );
}

pair<int, int> get_max(int v, int l, int r, int ll, int rr) {
    if (l == ll && rr == r) {
        return tree1[v];
    }

    pair<int, int> result(0, -1);
    int x = (l + r) / 2;
    if (ll <= x) {
        result = combine(result, get_max(v + v, l, x, ll, min(rr, x) ) );
    }
    if (x + 1 <= rr) {
        result = combine(result, get_max(v + v + 1, x + 1, r, max(x + 1, ll), rr) );
    }

    return result;
}

int range(int l, int r, int value) {
    auto it1 = positions[value].begin();
    auto it2 = positions[value].end();
    return (int)(upper_bound(it1, it2, r) - lower_bound(it1, it2, l) );
}

void process(int l, int r, int pos) {
    // cerr << "->>> " << l << " " << r << " " << pos << " " << pos - l << " " << r - pos << " " << flag << "\n";
    bool statement1 = pos - l < r - pos;
    bool statement2 = (pos - l == r - pos) && flag;
    if (statement1 || statement2) {
        for (int i = l; i <= pos; i++) {
            int value = (suff[i] - suff[pos] + k) % k;
            int pref_r = (pref[pos] - value + k) % k;
            // cerr << pos << " " << r << " " << pref_r << " " << range(pos, r, pref_r) << " " << range(pos, r, pref_r - 1) << "\n"; 
            answer += range(pos, r, pref_r);
        }
    } 
}

void rec(int l, int r) {
    if (l > r) {
        return;
    }

    int pos = get_max(1, 1, n, l, r).second;
    process(l, r, pos);
    rec(pos + 1, r);
    rec(l, pos - 1);
}

void solve1() {
    for (int i = 0; i < MAXK; i++) {
        positions[i].clear();
    }

    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] + a[i] ) % k;
    }

    suff[n + 1] = 0;
    for (int i = n; i >= 0; i--) {
        suff[i] = (suff[i + 1] + a[i] ) % k;
    }

    init1(1, 1, n);

    for (int i = 1; i <= n; i++) {
        positions[pref[i] ].push_back(i);
    }

    rec(1, n);
}

void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i] );
    }

    answer = 0ll;
    flag = false;
    solve1();
    flag = true;
    reverse(a + 1, a + n + 1);
    solve1();

    cout << answer - n << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}