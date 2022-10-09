
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

const int N = 105;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, m;
        cin >> n >> m;
        rep(i, 0, n) {
            cin >> s[i];
        }
        int cnt = 0;
        rep(i, 0, n - 1) {
            cnt += (s[i][m - 1] == 'R');
        }
        rep(i, 0, m - 1) {
            cnt += (s[n - 1][i] == 'D');
        }
        cout << cnt << '\n';
    }
}