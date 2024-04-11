
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

int t, n, k, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        set<int> se;
        for(int i = 0; i < n; i++) {
            cin >> a;
            se.insert(a);
        }
        if(se.size() > k) {
            cout << "-1\n";
        }else {
            cout << (n * k) << endl;
            for(int i = 1; i <= n && (int) se.size() < k; i++) {
                se.insert(i);
            }
            vi ve(all(se));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < k; j++) {
                    cout << ve[j] << ' ';
                }
            }
            cout << '\n';
        }
    }
}