
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

// sum of black = sum of white
// can we do greedy? Choose a node to be a leaf, attach it to some node of opposite color
// subtract value and contract.
// seems like it should work by induction.

const int N = 1e5 + 5;
int n;
bool c[N];
ll s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> v[2];
    rep(i, 1, n + 1) {
        cin >> c[i] >> s[i];
        v[c[i]].push_back(i);
    }
    int i = 0, j = 0;
    rep(t, 0, n - 1) {
        int x = v[0][i], y = v[1][j];
        cout << x << ' ' << y << ' ' << min(s[x], s[y]) << '\n';
        if(s[x] < s[y] || (s[x] == s[y] && i + 1 < sz(v[0]))) {
            i++;
            s[y] -= s[x];
        }else {
            j++;
            s[x] -= s[y];
        }
    }
}