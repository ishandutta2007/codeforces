#include <bits/stdc++.h>
using namespace std;

int K, n, m;
vector <int> rec;
bool ans;

void perform(int x) {
    rec.push_back(x);
    if (x == 0) K++;
    else {
        if (x > K) ans = false;
    }
}

void work() {
    vector <int> a, b;
    rec.clear(); ans = true;
    cin >> K >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            perform(a[i++]);
        } else {
            perform(b[j++]);
        }
    }
    while (i < n) perform(a[i++]);
    while (j < m) perform(b[j++]);
    if (ans) {
        for (auto i : rec) {
            printf("%d ", i);
        }
        puts("");
    } else puts("-1");
}

int main () {
    int T;
    cin >> T;
    while (T--) work();
}