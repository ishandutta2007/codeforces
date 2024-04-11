
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a = 0, b = 0, c = 0, d = 1;
    rep(i, 0, n) {
        ll a2 = b + c + d;
        ll b2 = a + c + d;
        ll c2 = a + b + d;
        ll d2 = a + b + c;
        a = a2 % M;
        b = b2 % M;
        c = c2 % M;
        d = d2 % M;
    }
    cout << d << '\n';
}