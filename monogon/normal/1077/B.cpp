
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

const int N = 105;
int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, n - 1) {
        if(a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            k++;
            a[i + 1] = 0;
        }
    }
    cout << k << '\n';
}