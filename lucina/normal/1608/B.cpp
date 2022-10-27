#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
using ll = int64_t;
int n, a, b;

void solve() {
    cin >> n >> a >> b;
    /**
        if we want b local maximums we
            2 * b + 1
    */
    vector <int> ans;
    if (abs(a - b) > 1) {
        cout << "-1\n";
        return;
    }
    if (a > b) {
        ans.push_back(1);
        ans.push_back(3);
        for (int i = 1 ; i <= b ; ++ i) {
            int v = ans.back();
            ans.push_back(v - 1);
            ans.push_back(v + 2);
        }
    } else {
        ans.push_back(2);
        ans.push_back(1);
        for (int i = 1 ; i <= a ; ++ i) {
            int v = ans.back();
            ans.push_back(v + 3);
            ans.push_back(v + 2);
        }
    }


    set <int> setik;
    for (int i = 0 ; i < ans.size() ; ++ i) {
        setik.insert(ans[i]);
        if (ans[i] > n) {
            cout << "-1\n";
            return;
        }
    }


    vector <int> bar;
    for (int i = n ; i >= 1 ; -- i) {
        if (!setik.count(i)) {
            bar.push_back(i);
        }
    }
    if (a == b) {
        for (int i : ans)
            bar.push_back(i);
        ans.swap(bar);
    } else if (a > b) {
        if (bar.empty()) {
            cout << "-1\n";
            return;
        }
        if (ans.back() < bar.back()) swap(ans.back(), bar.back());
        for (int i : bar) ans.push_back(i);
    } else if (b > a) {
        if (bar.empty()) {
            cout << "-1\n";
            return;
        }
        reverse(bar.begin(), bar.end());
        for (int i : bar) ans.push_back(i);
    }

    for (int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}