
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

const int N = 3005;
int cntA[N], cntB[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n + 1);
        rep(i, 1, n + 1) {
            cin >> a[i];
        }
        ll ans = 0;
        rep(i, 1, n + 1) {
            fill(cntA, cntA + n + 1, 0);
            fill(cntB, cntB + n + 1, 0);
            rep(j, i + 1, n + 1) {
                cntB[a[j]]++;
            }
            ll amt = 0;
            rep(k, i + 1, n + 1) {
                // remove a[k] from B
                amt -= cntA[a[k]];
                cntB[a[k]]--;
                if(a[i] == a[k]) {
                    ans += amt;
                }
                // add a[k] to A
                amt += cntB[a[k]];
                cntA[a[k]]++;
            }
        }
        cout << ans << '\n';
    }
}