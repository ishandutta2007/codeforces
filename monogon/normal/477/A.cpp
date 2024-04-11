
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

const int M = 1e9 + 7;

ll mod(ll a) {
    return (a % M + M) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << mod(mod(b * mod(a * (a + 1) / 2) + a) * mod(((b - 1) * b) / 2)) << '\n';
}