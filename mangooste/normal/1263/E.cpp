#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const int N = 1e6 + 2;
pii tree[4 * N];
int mod[4 * N];
char types[N];

inline void push(int v) {
    tree[v].first += mod[v];
    tree[v].second += mod[v];
    mod[2 * v] += mod[v];
    mod[2 * v + 1] += mod[v];
    mod[v] = 0;
}

void upd(int v, int vl, int vr, int L, int R, int del) {
    if (R <= vl || vr <= L)
        return;
    if (L <= vl && vr <= R) {
        mod[v] += del;
        return;
    }
    push(v);
    int vm = (vl + vr) / 2;
    upd(2 * v, vl, vm, L, R, del);
    upd(2 * v + 1, vm, vr, L, R, del);
    tree[v].first = min(tree[2 * v].first + mod[2 * v], tree[2 * v + 1].first + mod[2 * v + 1]);
    tree[v].second = max(tree[2 * v].second + mod[2 * v], tree[2 * v + 1].second + mod[2 * v + 1]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = 0, bal = 0;
    fill(types, types + N, 'a');
    fill(tree, tree + 4 * N, mp(0, 0));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            pos--;
        else if (s[i] == 'R')
            pos++;
        else {
            if (types[pos] == '(') {
                upd(1, 0, N, pos, N, -1);
                bal--;
            }
            if (types[pos] == ')') {
                upd(1, 0, N, pos, N, 1);
                bal++;
            }
            types[pos] = s[i];
            if (types[pos] == '(') {
                upd(1, 0, N, pos, N, 1);
                bal++;
            }
            if (types[pos] == ')') {
                upd(1, 0, N, pos, N, -1);
                bal--;
            }
        }
        if (pos == -1)
            pos = 0;
        push(1);
        pii chk = tree[1];
        if (bal == 0 && chk.first >= 0)
            cout << chk.second << ' ';
        else
            cout << "-1 ";
    }
    cout << '\n';
}