
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
        string s;
        int n, x;
        cin >> s >> x;
        n = s.length();
        string w(n, '1');
        rep(i, 0, n) {
            if(s[i] == '0') {
                if(i - x >= 0) w[i - x] = '0';
                if(i + x < n) w[i + x] = '0';
            }
        }
        rep(i, 0, n) {
            if(s[i] == '1' && (i - x < 0 || w[i - x] == '0') && (i + x >= n || w[i + x] == '0')) {
                cout << "-1\n";
                goto hell;
            }
        }
        cout << w << '\n';
        hell:;
    }
}