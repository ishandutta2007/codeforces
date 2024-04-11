#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int n, k;
vector<int> ve;

int ask(int u) {
    cout << "? ";
    for (int i = 1; i <= k + 1; i++) {
        if (u != i) {
            cout << i << " ";
        }
    }
    cout << endl;
    int val;
    cin >> val >> val;
    return val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= k + 1; i++) {
        ve.push_back(ask(i));
    }
    sort(ve.begin(), ve.end());
    int cnt = 0, fi = ve.back();
    for (int &v : ve) {
        cnt += (v == fi);
    }
    cout << "! " << cnt << endl;
}