
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

string s;
int k, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> k;
    n = s.length();
    if(n % k != 0) {
        cout << "NO\n";
        return 0;
    }
    int len = n / k;
    rep(i, 0, k) {
        int p = len * i;
        rep(j, 0, len) {
            if(s[p + j] != s[p + len - j - 1]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}