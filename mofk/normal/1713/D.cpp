#include<bits/stdc++.h>

using namespace std;

vector<int> init(int n) {
    vector<int> ret;
    for (int i = 0; i < (1 << n); ++i) ret.push_back(i + 1);
    return ret;
}

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ret;
    cin >> ret;
    if (ret == 1) return i;
    if (ret == 2) return j;
    return 0;
}

int ask(int i, int j, int k, int l) {
    int il = ask(i, l);
    if (il == i) return ask(i, k);
    if (il == l) return ask(j, l);
    return ask(j, k);
}

int solve(int n, vector<int> v) {
    if (n == 0) return v[0];
    if (n == 1) return ask(v[0], v[1]);
    vector<int> w;
    for (int i = 0; i < (1 << n - 2); ++i) {
        w.push_back(ask(v[i*4], v[i*4+1], v[i*4+2], v[i*4+3]));
    }
    return solve(n - 2, w);
}

int main(void) {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        int ans = solve(n, init(n));
        cout << "! " << ans << endl;
    }
    return 0;
}