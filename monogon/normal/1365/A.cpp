
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

const int N = 100;
int t, n, m, a;
bool r[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        fill(r, r + n, 0);
        fill(c, c + m, 0);
        rep(i, 0, n) rep(j, 0, m) {
            cin >> a;
            if(a) {
                r[i] = true;
                c[j] = true;
            }
        }
        int row = 0, col = 0;
        rep(i, 0, n) row += !r[i];
        rep(j, 0, m) col += !c[j];
        cout << (min(row, col) % 2 ? "Ashish" : "Vivek") << '\n';
    }
}