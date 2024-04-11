
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
    int n, k;
    cin >> n >> k;
    string s;
    rep(i, 0, k) {
        s.push_back('a' + i);
        for(int j = k - 1; j > i; j--) {
            s.push_back('a' + i);
            if(j != i + 1) s.push_back('a' + j);
        }
    }
    for(int i = k - 1; i > 0; i--) s.push_back('a' + i);
    int m = s.length();
    rep(i, 0, n) {
        cout << s[i % m];
    }
    cout << '\n';
}