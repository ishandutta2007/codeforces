
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

const int N = 2e5 + 5;
int n;
ll a[N];
map<ll, int> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        ma[a[i]]++;
    }
    vi ve;
    rep(i, 0, n) {
        if((sum - a[i]) % 2 == 0 && (ma[(sum - a[i]) / 2] >= 2 || (a[i] != (sum - a[i]) / 2 && ma[(sum - a[i]) / 2] >= 1))) {
            ve.push_back(i);
        }
    }
    cout << sz(ve) << '\n';
    for(int x : ve) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}