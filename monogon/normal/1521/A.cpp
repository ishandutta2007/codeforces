
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

// Ax + Ay = A kB
// 

void solve() {
    ll A, B;
    cin >> A >> B;
    if(B == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << A * (B + 1) << ' ' << A *(B - 1) << ' ' << A * B * 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}