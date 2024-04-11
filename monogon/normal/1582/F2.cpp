
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
    int n;
    cin >> n;
    const int A = 1 << 13;
    vector<vi> pos(5001);
    rep(i, 1, n + 1) {
        int a;
        cin >> a;
        pos[a].push_back(i);
    }
    vi minpos(A, INT_MAX), minpos2(A);
    minpos[0] = 0;
    rep(a, 0, 5001) {
        rep(i, 0, A) minpos2[i] = minpos[i];
        rep(i, 0, A) {
            if(minpos[i] < INT_MAX) {
                auto it = lower_bound(all(pos[a]), minpos[i]);
                if(it != pos[a].end()) {
                    int idx = *it;
                    minpos2[a ^ i] = min(minpos2[a ^ i], idx);
                }
            }
        }
        minpos.swap(minpos2);
    }
    vi ve;
    rep(i, 0, A) {
        if(minpos[i] < INT_MAX) ve.push_back(i);
    }
    cout << sz(ve) << '\n';
    for(int x : ve) cout << x << ' ';
    cout << '\n';
}