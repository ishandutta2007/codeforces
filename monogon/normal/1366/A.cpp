
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

int t;
ll a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        ll x = min(a, b - a);
        a -= x;
        b -= 2 * x;
        ll y = min(a, b) / 3;
        x += 2 * y;
        a -= 3 * y;
        b -= 3 * y;
        x += (a >= 1 && b >= 2) || (a >= 2 && b >= 1);
        cout << x << '\n';
    }
}