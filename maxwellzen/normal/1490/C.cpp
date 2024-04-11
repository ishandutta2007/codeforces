#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t;
ll n, a, b, c;

void solve() {
    cin >> n;
    b = cbrt(n);
    while (b*b*b<n) b++;
    while (b*b*b>n) b--;
    a = 1;
    while (a<=b) {
        c = a*a*a + b*b*b;
        if (c==n) {
            cout << "YES\n";
            return;
        } else if (c<n) a++;
        else if (c>n) b--;
    }
    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}