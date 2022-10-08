
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

const int N = 1e6 + 5;
int t, n;
ll f[N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        fill(f, f + n + 1, 0);
        int cnt = 0;
        rep(i, 0, n) {
            char c = s[i];
            cnt += (c == '+') - (c == '-');
            if(cnt < 0 && f[-cnt] == 0) {
                f[-cnt] = i + 1;
            }
        }
        cout << n + accumulate(f, f + n + 1, 0LL) << '\n';
    }
}