
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

const int K = 300;
int buff[K + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, te;
    cin >> n >> te;
    vi p(n + 1), pinv(n + 1), q(n + 1);
    rep(i, 1, n + 1) {
        cin >> p[i];
        pinv[p[i]] = i;
    }
    rep(i, 1, n + 1) {
        q[i] = i;
        rep(j, 0, K) {
            q[i] = p[q[i]];
        }
    }
    while(te--) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            int x, y;
            cin >> x >> y;
            swap(pinv[p[x]], pinv[p[y]]);
            swap(p[x], p[y]);
            // fix elements going forward and backward
            for(int i : {x, y}) {
                buff[0] = i;
                rep(j, 1, K + 1) {
                    buff[j] = p[buff[j - 1]];
                }
                rep(j, 0, K + 1) {
                    q[i] = buff[K - j];
                    i = pinv[i];
                }
            }
        }
        else {
            int i, k;
            cin >> i >> k;
            while(k >= K) {
                i = q[i];
                k -= K;
            }
            while(k > 0) {
                i = p[i];
                k--;
            }
            cout << i << '\n';
        }
    }
}