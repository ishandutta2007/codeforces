
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// put 2 in its place, then 3, then 4, ..., then n-1.
// then swap 1 and n if necessary.
// to put an element in its place, either directly swap with where it needs to be
// or move it to the farthest endpoint as an intermediate step.

const int MAX_N = 3e5 + 5;
int n, p[MAX_N], invp[MAX_N];
vector<pair<int, int>> swaps;

// indices to swap
void pswap(int i, int j) {
    swaps.push_back({i, j});
    swap(p[i], p[j]);
    swap(invp[p[i]], invp[p[j]]);
}
void fix(int val) {
    int idx = invp[val];
    if(idx == val) return;
    if(2 * abs(idx - val) >= n) {
        pswap(idx, val);
    }else if(2 * (idx - 1) >= n) {
        pswap(idx, 1);
        if(2 * (val - 1) >= n) {
            pswap(1, val);
        }else {
            pswap(1, n);
            pswap(n, val);
        }
    }else {
        pswap(idx, n);
        if(2 * (n - val) >= n) {
            pswap(n, val);
        }else {
            pswap(1, n);
            pswap(1, val);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        invp[p[i]] = i;
    }
    for(int i = 2; i <= n; i++) {
        fix(i);
    }
    cout << swaps.size() << endl;
    for(pair<int, int> s : swaps) {
        cout << s.first << " " << s.second << endl;
    }
}