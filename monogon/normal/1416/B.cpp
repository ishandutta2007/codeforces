
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
        vector<ll> a(n + 1, 0);
        ll sum = 0;
        rep(i, 1, n + 1) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n != 0) {
            cout << -1 << '\n';
            continue;
        }
        ll x = sum / n;
        vector<array<ll, 3>> ops;
        rep(i, 2, n + 1) {
            ll rem = ((-a[i] % i) + i) % i;
            array<ll, 3> A;
            A[0] = 1;
            A[1] = i;
            A[2] = rem;
            ops.push_back(A);
            array<ll, 3> B;
            B[0] = i;
            B[1] = 1;
            B[2] = (a[i] + rem) / i;
            ops.push_back(B);
        }
        rep(i, 2, n + 1) {
            ops.push_back({1, i, x});
        }
        cout << sz(ops) << '\n';
        for(auto &A : ops) {
            cout << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
            int i = A[0], j = A[1], v = A[2];
            a[i] -= v * i;
            a[j] += v * i;
        }
        // cout << "check: ";
        // rep(i, 1, n + 1) cout << a[i] << ' ';
        // cout << endl;
    }
}