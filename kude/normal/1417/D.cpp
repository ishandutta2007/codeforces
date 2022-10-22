#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

struct S {
    int i, j, x;
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        VI a(n+1);
        rep(i, n) cin >> a[i+1];
        // 1-indexed
        int s = 0;
        rep(i, n) s += a[i+1];
        if (s % n != 0) {
            cout << -1 << endl;
            continue;
        }
        int trg = s / n;
        vector<S> ops;
        auto mv = [&](int i, int j, int x) {
            ops.push_back({i, j, x});
            a[i] -= i * x;
            a[j] += i * x;
        };
        for(int i = 1; i + 1 <= n; i++) {
            int x = a[i] / i;
            mv(i, i+1, x);
        }
        {
            int x = a[n] / n;
            mv(n, 1, x);
        }
        auto cmp = [&](int i, int j) {
            return a[i] < a[j];
        };
        priority_queue<int, VI, decltype(cmp)> q(cmp);
        for(int i = 2; i <= n; i++) q.push(i);
        while(!q.empty()) {
            int i = q.top(); q.pop();
            if (a[i] < trg) {
                mv(1, i, trg - a[i]);
            } else if (a[i] > trg) {
                int dif = a[i] - trg;
                int r = dif % i;
                if (r != 0) {
                    mv(1, i, i-r);
                }
                mv(i, 1, (a[i]-trg) / i);
            }
        }
        assert(a[1] == trg);
        //for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
        cout << ops.size() << '\n';
        for(auto& s: ops) {
            cout << s.i << ' ' << s.j << ' ' << s.x << '\n';
        }
    }
}