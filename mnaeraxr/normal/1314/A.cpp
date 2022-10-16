#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n), b(n), o(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) o[i] = i;

    long long answer = 0;

    sort(o.begin(), o.end(), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] < a[j];
        return b[i] < b[j];
    });

    long long active = 0;
    multiset<int> ms;

    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[o[j]] == a[o[i]]; ++j) {
            active += b[o[j]];
            ms.insert(b[o[j]]);
        }

        int cur_pub = a[o[i]];
        int nxt_pub = j == n ? 2000000000 : a[o[j]];

        while (cur_pub < nxt_pub && !ms.empty()) {
            auto it = ms.end(); --it;
            active -= *it;
            ms.erase(it);
            answer += active;
            cur_pub++;
        }
    }

    cout << answer << endl;

    return 0;
}