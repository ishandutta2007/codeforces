#include<bits/stdc++.h>
using namespace std;
int n;
vector <pair< int64_t, int64_t>> ans;
void add_ans(int x, int y) {
    ans.emplace_back(x, y);
}

void solve() {
    cin >> n;
    vector <int64_t> a(n);
    iota(a.begin(), a.end(), 1);
    ans.clear();
    while (a.size() > 1) {
        int64_t b = a.back();
        a.pop_back();
        int pos = -1;
        for (int i = int(a.size()) - 1 ; i >= 0 ; -- i) {
            if (a[i] % 2 == b % 2) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            pos = int(a.size()) - 1;
        }
        swap(a[pos], a.back());
        int64_t bar = a.back();
        add_ans(bar, b);
        a.pop_back();
        a.push_back((bar + b + 1) / 2);
    }

    cout << a.back() << '\n';
    for (auto &[foo, bar] : ans)
        cout << foo << ' ' << bar << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}