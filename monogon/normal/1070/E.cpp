
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int q, n, m;
ll t, p[N];

int check(int d) {
    ll ti = 0;
    int task = 0;
    ll sumti = 0;
    rep(i, 0, n) {
        if(ti > t) break;
        if(p[i] <= d && ti + p[i] <= t) {
            task++;
            ti += p[i];
            sumti += p[i];
            if(task % m == 0) {
                ti += sumti;
                sumti = 0;
            }
        }else if(p[i] <= d) break;
    }
    return task;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> m >> t;
        vi ve;
        rep(i, 0, n) {
            cin >> p[i];
            if(p[i] <= t) {
                ve.push_back(p[i]);
            }
        }
        sort(all(ve));
        ve.erase(unique(all(ve)), ve.end());
        int L = 0, R = sz(ve) - 1;
        while(R - L >= 3) {
            int m1 = L + (R - L) / 3;
            int m2 = L + 2 * (R - L) / 3;
            if(check(ve[m1]) < check(ve[m2])) {
                L = m1 + 1;
            }else {
                R = m2;
            }
        }
        if(ve.empty()) {
            cout << "0 1\n";
        }else {
            int d = ve[L], ans = check(ve[L]); L++;
            while(L <= R) {
                int tasks = check(ve[L]);
                if(tasks > ans) {
                    ans = tasks;
                    d = ve[L];
                }
                L++;
            }
            cout << ans << ' ' << d << '\n';
        }
    }
}