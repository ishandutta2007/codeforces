
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n) cin >> a[i];
        swap(a[0], a[max_element(all(a)) - a.begin()]);
        int prefg = a[0];
        rep(i, 1, n) {
            int idx = i;
            int g = -1;
            rep(j, i, n) {
                int g2 = gcd(prefg, a[j]);
                if(g2 > g) {
                    g = g2;
                    idx = j;
                }
            }
            swap(a[idx], a[i]);
            prefg = g;
        }
        for(int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}