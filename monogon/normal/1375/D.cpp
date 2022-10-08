
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

const int N = 1005;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        set<int> s;
        map<int, int> cnt;
        for(int i = 0; i <= n; i++) {
            s.insert(i);
        }
        rep(i, 0, n) {
            cin >> a[i];
            cnt[a[i]]++;
            s.erase(a[i]);
        }
        vector<int> ops;
        int idx = 0;
        auto upd = [&](int i, int mex) {
            ops.push_back(i + 1);
            cnt[a[i]]--;
            if(cnt[a[i]] == 0) {
                s.insert(a[i]);
            }
            a[i] = mex;
            cnt[mex]++;
            s.erase(mex);
        };
        while(idx < n) {
            int mex = *s.begin();
            if(mex < n) {
                upd(mex, mex);
            }else {
                while(idx < n && a[idx] == idx) idx++;
                if(idx < n) {
                    upd(idx, mex);
                }
            }
        }

        cout << sz(ops) << '\n';
        for(int x : ops) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}