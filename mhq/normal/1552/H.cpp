#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int ask(vector<pair<int,int>>& all) {
    cout << "? " << all.size() << endl;
    for (auto& it : all) cout << it.first << " " << it.second << " ";
    cout << endl;
    int resp;
    cin >> resp;
    return resp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    const int maxS = 200;
    vector<pair<int,int>> z;
    for (int i = 1; i <= maxS; i++) {
        for (int j = 1; j <= maxS; j++) {
            z.emplace_back(i, j);
        }
    }
    int area = ask(z);
    int l = 0;
    int r = 8;
    int last_bad = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pw = (1 << mid);
        vector<pair<int,int>> t;
        for (int i = pw; i <= maxS; i += pw) {
            for (int j = 1; j <= maxS; j++) {
                t.emplace_back(i, j);
            }
        }
        int c = ask(t);
        if (area == c * pw) {
            l = mid;
        }
        else {
            r = mid;
            last_bad = c;
        }
    }
    //last_bad
    int A = 0;
    if (r == 8) {
        A = 128;
    }
    else {
        int pw = (1 << r);
        if (area > last_bad * pw) {
            for (int k = 0; k <= 500; k++) {
                if (area * k == last_bad * (pw * k + pw / 2)) {
                    A = pw * k + pw / 2;
                    break;
                }
            }
        }
        else {
            for (int k = 0; k <= 500; k++) {
                if (area * (k + 1) == last_bad * (pw * k + pw / 2)) {
                    A = pw * k + pw / 2;
                    break;
                }
            }
        }
    }
    int B = area / A;
    A--;
    B--;
    cout << "! " << 2 * (A + B) << endl;
    return 0;
}