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

vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> c(4, -1000000);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int u = ((i & 1) << 1) | (j & 1);
            int v = (((i >> 1) & 1) << 1) | ((j >> 1) & 1);

            if (u && v)
                c[3] = max(c[3], a[i] + b[j] + 3);
            else if (u) {
                if (u == 3) {
                    c[3] = max(c[3], a[i] + b[j] + 3);
                } else {
                    c[1] = max(c[1], a[i] + b[j] + 1);
                    c[2] = max(c[2], a[i] + b[j] + 2);
                }
            } else if (v) {
                c[2] = max(c[2], a[i] + b[j] + 2);
            } else {
                c[0] = max(c[0], a[i] + b[j]);
            }
        }
    }

    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    n = 1 << n;
    vector<int> b(n);

    for (int i = 0; i < k; ++i) {
        int u; cin >> u; u--;
        b[u] = true;
    }

    vector<vector<int>> t(n / 2, vector<int>(4, -1000000));

    for (int i = 0; i < n; i += 2) {
        if (max(b[i], b[i + 1]) == 0) {
            t[i / 2][0] = 0;
        } else if (min(b[i], b[i + 1]) == 1) {
            t[i / 2][3] = 1;
        } else {
            t[i / 2][1] = t[i / 2][2] = 1;
        }
    }

    // for (auto r : t) {
    //     for (auto x : r)
    //         cout << x << " ";
    //     cout << endl;
    // }

    while (t.size() > 1) {
        vector<vector<int>> nt;
        for (int i = 0; i < t.size(); i += 2) {
            nt.push_back(merge(t[i], t[i + 1]));
        }
        t.swap(nt);
        
        // cout << endl;
        // for (auto r : t) {
        //     for (auto x : r)
        //         cout << x << " ";
        //     cout << endl;
        // }
    }

    int answer = t[0][0];

    for (int i = 1; i < 4; ++i)
        answer = max(answer, t[0][i] + 1);

    cout << answer << endl;

    return 0;
}