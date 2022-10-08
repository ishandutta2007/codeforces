
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        int mi = *min_element(all(a));
        vector<pii> ve;
        rep(i, 0, n) {
            if(a[i] % mi == 0) {
                ve.emplace_back(a[i], i);
            }
        }
        sort(all(ve));
        int idx = 0;
        rep(i, 0, n) {
            if(a[i] % mi == 0) {
                a[i] = ve[idx].first;
                idx++;
            }
        }
        if(is_sorted(all(a))) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}