
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
    vi b(n);
    vector<vi> ve(2);
    rep(i, 0, n) {
        cin >> b[i];
        ve[b[i] % 2].push_back(b[i]);
    }
    if(n == 2) {
        if(b[0] == b[1]) {
            cout << "YES\n" << b[0] << ' ' << 0 << '\n';
        }else {
            cout << "NO\n";
        }
        return 0;
    }else if(n == 3) {
        if((b[0] + b[1] + b[2]) % 2 == 0) {
            int s = (b[0] + b[1] + b[2]) / 2;
            cout << "YES\n" << s - b[0] << ' ' << s - b[1] << ' ' << s - b[2] << '\n';
        }else {
            cout << "NO\n";
        }
        return 0;
    }
    if(!ve[0].empty()) {
        cout << "YES\n";
        int x = 0, y = 0, z = 0;
        if(sz(ve[0]) >= 3) {
            x = ve[0][sz(ve[0]) - 1], y = ve[0][sz(ve[0]) - 2], z = ve[0][sz(ve[0]) - 3];
            rep(i, 0, 3) ve[0].pop_back();
        }else {
            x = ve[0][sz(ve[0]) - 1], y = ve[1][sz(ve[1]) - 1], z = ve[1][sz(ve[1]) - 2];
            ve[0].pop_back();
            rep(i, 0, 2) ve[1].pop_back();
        }
        assert((x + y + z) % 2 == 0);
        int s = (x + y + z) / 2;
        vi a;
        a.push_back(s - x);
        a.push_back(s - y);
        a.push_back(s - z);
        for(int val : ve[0]) a.push_back(val - a.back());
        for(int val : ve[1]) a.push_back(val - a.back());
        for(int val : a) cout << val << ' ';
        cout << '\n';
        return 0;
    }
    // all odd, must be even length cycle
    int k = min(n, 17);
    vi sign(k);
    auto dfs = [&](auto dfs, int idx, int sum, int balance) -> void {
        if(abs(balance) > k - idx) return;
        if(idx == k) {
            if(sum == 0) {
                bool ok = false;
                for(int x : sign) if(x != 0) {
                    ok = true;
                    break;
                }
                if(!ok) return;
                cout << "YES\n";
                vi A, B, C;
                rep(i, 0, k) {
                    if(sign[i] == -1) A.push_back(b[i]);
                    else if(sign[i] == 1) B.push_back(b[i]);
                    else C.push_back(b[i]);
                }
                rep(i, k, n) C.push_back(b[i]);
                
                vi a;
                int sum = 0;
                assert(sz(A) == sz(B));
                rep(i, 0, sz(A)) {
                    sum += A[i];
                    a.push_back(sum);
                    sum -= B[i];
                    a.push_back(-sum);
                }
                sum = 0;
                for(int x : C) {
                    a.push_back(x);
                    sum += x;
                }
                for(int x : a) cout << x << ' ';
                cout << '\n';

                exit(0);
            }else return;
        }
        sign[idx] = -1;
        dfs(dfs, idx + 1, sum - b[idx], balance - 1);
        sign[idx] = 0;
        dfs(dfs, idx + 1, sum, balance);
        sign[idx] = 1;
        dfs(dfs, idx + 1, sum + b[idx], balance + 1);
    };
    dfs(dfs, 0, 0, 0);
    cout << "NO\n";
}