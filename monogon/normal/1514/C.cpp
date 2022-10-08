
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
    int n;
    cin >> n;
    vi ve;
    ll prod = 1;
    rep(i, 1, n) {
        if(gcd(i, n) == 1) {
            ve.push_back(i);
            prod = (prod * i) % n;
        }
    }
    if(prod != 1) {
        ve.erase(find(all(ve), prod));
    }
    cout << sz(ve) << '\n';
    for(int x : ve) {
        cout << x << ' ';
    }
    cout << '\n';
}