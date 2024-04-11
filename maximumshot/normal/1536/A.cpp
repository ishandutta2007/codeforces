#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set<int> q(a.begin(), a.end());
        const int K = 310;
        while ((int) a.size() < K) {
            int any = 0;
            for (int i = 0; i < (int) a.size() && (int) a.size() < K; i++) {
                for (int j = 0; j < i && (int) a.size() < K; j++) {
                    int x = abs(a[i] - a[j]);
                    if (!q.count(x)) {
                        q.insert(x);
                        a.push_back(x);
                        any = 1;
                    }
                }
            }
            if (any) continue;
            break;
        }
        if ((int) a.size() <= 300) {
            cout << "YES\n";
            cout << (int) a.size() << "\n";
            for (auto x : a)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}