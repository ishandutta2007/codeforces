#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
long long ar[N];

long long ask(int t, int l, int m, int r) {
    cout << t << " " << l << " " << m << " " << r << endl;
    long long ret; cin >> ret; return ret;
}

void solve(list<int> &li, int id) {
    ar[id] = ask(1, 1, id, n);
    if (li.size() == 2) {
        li.insert(next(li.begin()), id);
    } else {
        list<int>::iterator l, r;
        for (auto it = li.begin(); ar[*it] <= ar[*next(it)]; it = next(it)) {
            if (ar[*it] <= ar[id]) {
                l = it;
            }
        }
        for (auto it = prev(li.end()); ar[*it] <= ar[*prev(it)]; it = prev(it)) {
            if (ar[*it] <= ar[id]) {
                r = it;
            }
        }
        if (ask(2, *l, id, *next(l)) == 1) {
            li.insert(next(l), id);
        } else {
            li.insert(r, id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    list<int> hi = {1, n}, lo = {n, 1};
    for (int i = 2; i < n; i++) {
        if (ask(2, 1, i, n) == 1) {
            solve(hi, i);
        } else {
            solve(lo, i);
        }
    }
    cout << "0 ";
    for (int &v : hi) {
        if (v != n) {
            cout << v << " ";
        }
    }
    for (int &v : lo) {
        if (v != 1) {
            cout << v << " ";
        }
    }
    cout << endl;
}