#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Segment {
    ll l;
    ll r;
    int id;

    bool operator<(const Segment& s) const {
        return l < s.l || l == s.l && r > s.r;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);
    
    int n;
    cin >> n;
    vector<Segment> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].l >> s[i].r;
        s[i].id = i + 1;
    }
    sort(s.begin(), s.end());
    int mx = 0;
    int idx = 0;
    for (auto ss : s) {
        if (mx >= ss.r) {
            cout << ss.id << " " << idx << endl;
            return 0;
        }
        if (ss.r > mx) {
            mx = ss.r;
            idx = ss.id;
        }
    }
    cout << "-1 -1" << endl;
}