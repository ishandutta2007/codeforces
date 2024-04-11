#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if (abs(a + c - b - d) > 1) {
        cout << "NO\n";
        return 0;
    }

    auto check = [&](vector<int> p) -> bool {
        vector<int> cnt(4, 0);
        for (int i = 0; i < (int) p.size(); i++) {
            if (i + 1 < (int) p.size() && abs(p[i] - p[i + 1]) != 1)
                return false;
            cnt[p[i]]++;
        }
        return cnt[0] == a && cnt[1] == b && cnt[2] == c && cnt[3] == d;
    };

    int n = a + b + c + d;
    vector<int> p;

    if (a + c > b + d) {
        vector<int> cnt = {a, b, c, d};
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                if (cnt[1])
                    p.push_back(1), cnt[1]--;
                else
                    p.push_back(3), cnt[3]--;
            } else {
                if (cnt[0])
                    p.push_back(0), cnt[0]--;
                else
                    p.push_back(2), cnt[2]--;
            }
        }
    } else {
        vector<int> cnt = {a, b, c, d};
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (cnt[3])
                    p.push_back(3), cnt[3]--;
                else
                    p.push_back(1), cnt[1]--;
            } else {
                if (cnt[2])
                    p.push_back(2), cnt[2]--;
                else
                    p.push_back(0), cnt[0]--;
            }
        }
    }

    if (check(p)) {
        cout << "YES\n";
        for (int x : p) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}