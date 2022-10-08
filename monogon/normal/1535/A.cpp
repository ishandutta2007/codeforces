
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

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int w = max(a, b), w2 = max(c, d);
    vi ve = {a, b, c, d};
    sort(all(ve));
    if((w == ve[2] && w2 == ve[3]) || (w == ve[3] && w2 == ve[2])) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}