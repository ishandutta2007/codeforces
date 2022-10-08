
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// if r - l >= 2 * (a + b), the answer is a + 1
// [1 2 3 ... a] [x x x x] [<-- a -->] [y .. y] [<-- a -->] [z .. z]
// [1 2 3 4 5 6]

int a, b;
ll l, r;

vector<int> push(vector<int> &v) {
    set<int> se;
    for(int i = 0; i < a && i < (int) v.size(); i++) {
        se.insert(v[(int) v.size() - i - 1]);
    }
    int sz = v.size();
    for(int i = 1; (int) v.size() < sz + a; i++) {
        assert(i <= 26);
        if(se.count(i) == 0) v.push_back(i);
    }
    return v;
}

int solve(int L, int R, int x, int y, int z) {
    vector<int> v;
    push(v);
    for(int i = 1; i <= b; i++) v.push_back(x);
    push(v);
    for(int i = 1; i <= b; i++) v.push_back(y);
    push(v);
    for(int i = 1; i <= b; i++) v.push_back(z);

    set<int> se;
    for(int i = L; i <= R; i++) {
        se.insert(v[i]);
    }
    return se.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> l >> r;
    l--; r--;
    ll L = l % (a + b);
    ll R = L + (r - l);
    if(R - L >= 2 * (a + b)) {
        L = 0;
        R = 3 * (a + b) - 1;
    }
    int ans = R - L + 1;
    for(int x = 1; x <= 26; x++) {
        for(int y = 1; y <= 26; y++) {
            for(int z = 1; z <= 26; z++) {
                ans = min(ans, solve(L, R, x, y, z));
            }
        }
    }
    cout << ans << endl;
}