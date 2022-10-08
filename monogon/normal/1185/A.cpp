
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

ll a[3], d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a, a + 3);
    cout << max(0LL, d - a[2] + a[1]) + max(0LL, d - a[1] + a[0]) << '\n';
}