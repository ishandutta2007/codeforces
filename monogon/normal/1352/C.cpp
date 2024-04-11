
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

int t;
ll n, k;

// X 1 2 3 X 5 6 7
// 1 | 1
// 2 | 2
// 3 | 3
// n - 1 | n - 1
// n | n + 1
// n 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << 1 + n * ((k - 1) / (n - 1)) + ((k - 1) % (n - 1)) << '\n';
    }
}