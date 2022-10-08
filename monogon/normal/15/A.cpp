
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n, t, x, a, L[N], R[N];

bool overlap(int l1, int r1, int l2, int r2) {
    return l2 < r1 && l1 < r2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    set<int> se;
    for(int i = 0; i < n; i++) {
        cin >> x >> a;
        L[i] = 2 * x - a;
        R[i] = 2 * x + a;
        se.insert(L[i] - t);
        se.insert(R[i] + t);
    }
    int cnt = 0;
    for(int x : se) {
        for(int i = 0; i < n; i++) {
            if(overlap(L[i], R[i], x - t, x + t)) goto endloop;
        }
        cnt++;
        endloop:;
    }
    cout << cnt << endl;
}