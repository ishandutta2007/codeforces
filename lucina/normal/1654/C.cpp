#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int64_t a[nax];
vector <int64_t> split_set(vector <int64_t> x) {
    vector <int64_t> res;
    for (int64_t j : x) {
        res.push_back(j / 2);
        res.push_back((j + 1) / 2);
    }
    sort(res.begin(), res.end());
    return res;
}

bool solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    vector <int64_t> s = {accumulate(a + 1, a + 1 + n, 0LL)};
    multiset <int64_t> need(a + 1, a + 1 + n);
    while (!need.empty() && !s.empty() && s.size() <= need.size()) {
        vector <int64_t> new_s;
        for (int64_t j : s) {
            if (need.find(j) != need.end()) {
                need.erase(need.find(j));
            } else new_s.push_back(j);
        }
        s = split_set(new_s);
    }
    return need.empty();
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}