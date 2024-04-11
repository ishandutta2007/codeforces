
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
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int i = 0;
        while((1LL << i) - 1 < n) i++;
        ll x = (1LL << i) - 1 - n;
        vi ve(i, 0);
        for(int j = i; x > 0 && j > 0; j--) {
            while((1LL << j) - 1 <= x) {
                x -= (1LL << j) - 1;
                ve[i - j]++;
            }
        }
        cout << sz(ve) - 1 << '\n';
        for(int j = 1; j < i; j++) {
            ve[j] += 2 * ve[j - 1];
            ve[j - 1] = (1LL << (j - 1)) - 1 - ve[j - 1];
            cout << (1LL << j) - 1 - ve[j] - ve[j - 1] << ' ';
        }
        cout << '\n';
    }
}