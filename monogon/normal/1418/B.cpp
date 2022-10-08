
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
        vi a(n), l(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        vi ve;
        rep(i, 0, n) {
            cin >> l[i];
            if(l[i] == 0) ve.push_back(a[i]);
        }
        sort(ve.rbegin(), ve.rend());
        int idx = 0;
        rep(i, 0, n) {
            if(l[i] == 0) {
                a[i] = ve[idx];
                idx++;
            }
        }
        rep(i, 0, n) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}