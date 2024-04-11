
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

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int L = 0, R = 1e9;
    string s, s2;
    cout << "0 1" << endl;
    cin >> s;
    rep(i, 1, n) {
        int m = L + (R - L + 1) / 2;
        cout << m << ' ' << 1 << endl;
        cin >> s2;
        if(s2 == s) {
            L = m;
        }else {
            R = m;
        }
    }
    cout << L << ' ' << 2 << ' ' << R << ' ' << 0 << endl;
}