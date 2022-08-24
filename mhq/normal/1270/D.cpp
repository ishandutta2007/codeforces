#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
pair < int, int > ask(vector < int >& inds) {
    cout << "? ";
    for (int v : inds) cout << v << " ";
    cout << endl;
    int pos, val;
    cin >> pos >> val;
    return {pos, val};
}
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    n = k + 1;
    vector < int > v(k);
    iota(v.begin(), v.end(), 1);
    auto it = ask(v);
    int pos = it.first;
    v[pos - 1] = n;
    auto it2 = ask(v);
    v[pos - 1] = pos;
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        if (i == pos) continue;
        v[i - 1] = n;
        auto it3 = ask(v);
        if (it3.second == it.second) {
            cnt += !(it2.second > it.second);
        }
        else {
            cnt += (it2.second > it.second);
        }
        v[i - 1] = i;
    }
    cout << "! " << cnt + 1 << endl;
    return 0;
}