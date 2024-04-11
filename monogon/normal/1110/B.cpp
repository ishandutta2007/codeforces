
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

const int N = 1e5 + 5;
int n, k;
ll m, b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vi ve;
    ll len = n;
    rep(i, 0, n) {
        cin >> b[i];
        if(i > 0) {
            ve.push_back(b[i] - b[i - 1] - 1);
            len += b[i] - b[i - 1] - 1;
        }
    }
    sort(ve.rbegin(), ve.rend());
    rep(i, 0, k - 1) {
        len -= ve[i];
    }
    cout << len << '\n';
}