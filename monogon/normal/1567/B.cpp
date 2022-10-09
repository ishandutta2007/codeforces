
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

const int N = 3e5 + 5;
int x[N];

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if(x[a] == b) {
        ans = a;
    }else if((x[a] ^ b) != a) {
        ans = a + 1;
    }else {
        ans = a + 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    x[0] = 0;
    rep(i, 1, N) {
        x[i] = x[i - 1] ^ (i - 1);
    }
    int te;
    cin >> te;
    while(te--) solve();
}