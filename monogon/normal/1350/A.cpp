
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

// if n is odd, it will be even next
// if even, always add 2

int t;
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll p = 2;
        while(n % p != 0) p++;
        n += p;
        k--;
        cout << n + 2 * k << '\n';
    }
}