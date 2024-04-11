
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
        ll a, b, c;
        cin >> a >> b >> c;
        if((a + b + c) % 9 == 0 && min({a, b, c}) >= (a + b + c) / 9) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}