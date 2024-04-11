
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

const int N = 55;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vi v[2];
        rep(i, 0, n) {
            cin >> a[i];
            v[a[i] % 2].push_back(a[i]);
        }
        if(sz(v[0]) % 2 == 0 && sz(v[1]) % 2 == 0) {
            cout << "YES\n";
        }else {
            for(int x : v[0]) {
                for(int y : v[1]) {
                    if(abs(x - y) == 1) {
                        cout << "YES\n";
                        goto lab;
                    }
                }
            }
            cout << "NO\n";
        }
        lab:;
    }
}