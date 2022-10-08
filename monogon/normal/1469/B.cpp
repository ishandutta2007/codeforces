
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
        vi r(n + 1, 0);
        rep(i, 1, n + 1) {
            cin >> r[i];
            r[i] += r[i - 1];
        }
        int m;
        cin >> m;
        vi b(m + 1, 0);
        rep(i, 1, m + 1) {
            cin >> b[i];
            b[i] += b[i - 1];
        }
        cout << *max_element(all(r)) + *max_element(all(b)) << '\n';
    }
}