#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

vector<int> v;

bool solve() {
    while (true) {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 2048) {
                return 1;
            }
        }
        bool fnd = 0;
        for (int i = 0; i + 1 < v.size(); ++i) {
            if (v[i] > 2048) {
                break;
            }
            if (v[i] == v[i + 1]) {
                int cur = v[i];
                v.erase(v.begin() + i);
                v.erase(v.begin() + i);
                v.PB(cur * 2);
                fnd = 1;
                break;
            }
        }
        if (!fnd) {
            return false;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        v.clear();
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            v.PB(a);
        }
        cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}