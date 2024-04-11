
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
ll a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        if((a == c && b + d == a) || (a == d && b + c == a) || (b == c && a + d == b) || (b == d && a + c == b)) {
            cout << "YES\n";
        }else cout << "NO\n";
    }
}