#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> left, right;
    vector<int> odd, even;

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int e = n / 2, o = n - e;

    int complexity = 0, zero = 0;
    int last = -1, gap = 0;

    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;

        if (u == 0) {
            gap++;
            zero++;
        } else {
            ((u & 1) ? o : e)--;

            if (last == -1) {
                left = {gap, u & 1};
            } else {
                if ((last & 1) != (u & 1)) {
                    complexity++;
                } else if (last & 1) {
                    if (gap) odd.push_back(gap);
                } else {
                    if (gap) even.push_back(gap);
                }
            }

            last = u;
            gap = 0;
        }
    }

    right = {gap, last & 1};

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    if (zero == n) {
        cout << 1 << endl;
        return 0;
    }

    int answer = n;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int cur = complexity + i + j;
            int oo = o, ee = e;

            if (i == 0) (left.second ? oo : ee) -= left.first;
            if (j == 0) (right.second ? oo : ee) -= right.first;

            if (min(oo, ee) < 0) continue;

            cur += 2 * (odd.size() + even.size());

            for (auto x : odd) {
                if (oo >= x) {
                    cur -= 2;
                    oo -= x;
                }
            }

            for (auto x : even) {
                if (ee >= x) {
                    cur -= 2;
                    ee -= x;
                }
            }

            answer = min(answer, cur);
        }
    }

    cout << answer << endl;

    return 0;
}