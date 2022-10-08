
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

int n;

vi query(int r) {
    cout << "? " << r << endl;
    vi d(n + 1);
    rep(i, 1, n + 1) cin >> d[i];
    return d;
}

void answer(set<pii> e) {
    cout << "!" << endl;
    for(auto &pa : e) {
        cout << pa.first << ' ' << pa.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi dr = query(1);
    int cnt0 = 0, cnt1 = 0;
    set<pii> e;
    auto add = [&](int u, int v) {
        if(u > v) swap(u, v);
        e.insert({u, v});
    };
    rep(i, 1, n + 1) {
        (dr[i] % 2 == 0 ? cnt0 : cnt1)++;
        if(dr[i] == 1) add(1, i);
    }
    if(cnt0 <= cnt1) {
        rep(i, 2, n + 1) {
            if(dr[i] % 2 == 0) {
                vi d = query(i);
                rep(j, 1, n + 1) {
                    if(d[j] == 1) add(i, j);
                }
            }
        }
        answer(e);
    }else {
        int special = -1;
        rep(i, 1, n + 1) {
            if(dr[i] == 1) {
                special = i;
                break;
            }
        }
        vector<bool> ok(n + 1, false);
        rep(i, 1, n + 1) {
            if(dr[i] % 2 == 1 && i != special) {
                vi d = query(i);
                rep(j, 1, n + 1) {
                    if(d[j] == 1) {
                        add(i, j);
                        if(dr[j] == 2 && dr[i] == 1) ok[j] = true;
                    }
                }
            }
        }
        rep(i, 1, n + 1) {
            if(dr[i] == 2 && !ok[i]) add(special, i);
        }
        answer(e);
    }
}