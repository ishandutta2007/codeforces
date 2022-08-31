#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e5 + 10;
const int inf = (int)1e9;
pair < int, vector < int > > solve(vector < int > a, int pw) {
    //sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    //for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    //cout << endl;
    if (pw == (1 << 19)) {
        vector < int > s;
        if (a.size() == 0) return make_pair(0, s);
        if (a.size() != 1) {
            return make_pair(inf, s);
        }
        if (a[0] != 0) return make_pair(inf, s);
        return make_pair(0, s);
    }
    bool ok = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 != 0) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        for (int i = 0; i < a.size(); i++) a[i] /= 2;
        return solve(a, 2 * pw);
    }
    vector < int > can1, can2;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 == 0) {
            can1.push_back(a[i] / 2);
            can2.push_back(a[i] / 2);
        }
        else {
            can1.push_back((a[i] - 1) / 2);
            can2.push_back((a[i] + 1) / 2);
        }
    }
    auto get1 = solve(can1, 2 * pw);
    auto get2 = solve(can2, 2 * pw);
    //cout << a.size() << endl;
    if (get1.first < get2.first) {
        get1.second.push_back(pw / 2);
        return make_pair(get1.first + 1, get1.second);
    }
    else {
        get2.second.push_back(-(pw / 2));
        return make_pair(get2.first + 1, get2.second);
    }
}
vector < int > a;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    auto it = solve(a, 2);
    cout << it.first << '\n';
    for (int i = 0; i < it.second.size(); i++) cout << it.second[i] << " ";
    return 0;
}