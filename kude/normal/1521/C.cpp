#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int query1(int i, int j, int x) {
    cout << "? " << 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
    int ret;
    cin >> ret;
    return ret;
}
int query2(int i, int j, int x) {
    cout << "? " << 2 << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int p = 0, q = 1;
        int n;
        cin >> n;
        int M = query1(p, q, n - 1);
        if (M == n - 1) {
            swap(p, q);
            M = query1(p, q, n - 1);
        }
        int M2 = query1(p, q, M - 1);
        // if M2 == M, a_q = M else a_p = M
        if (M2 == M) {
            swap(p, q);
        }
        // a_p = M
        VI a(n);
        a[p] = M;
        //cout << "tt" << p << ' ' << M << endl;
        rep(i, n) if (i != p) {
            //cout << "sss" << i << endl;
            if (M <= n / 2) {
                int t = query1(p, i, n - 1);
                if (t > M) {
                    a[i] = t;
                    continue;
                }
                t = query2(i, p, 1);
                a[i] = t;
            } else {
                int t = query2(i, p, 1);
                if (t < M) {
                    a[i] = t;
                    continue;
                }
                t = query1(p, i, n - 1);
                a[i] = t;
            }
        }
        cout << "! ";
        rep(i, n) cout << a[i] << " \n"[i + 1 == n];
        cout << flush;
    }
}