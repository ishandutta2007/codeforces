
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
        int n;
        cin >> n;
        vector<ll> a(n);
        ll S[2] = {0, 0};
        rep(i, 0, n) {
            cin >> a[i];
            S[i % 2] += abs(a[i] - 1);
        }
        int b = min_element(S, S + 2) - S;
        rep(i, 0, n) {
            if(i % 2 == b) {
                cout << 1 << ' ';
            }else {
                cout << a[i] << ' ';
            }
        }
        cout << '\n';
    }
}