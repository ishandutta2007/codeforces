
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

const int N = 5e5 + 5;
int t, n;
ll k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool flag = false;
        rep(i, 0, n) {
            cin >> a[i];
            flag |= (a[i] == k);
        }
        if(!flag) {
            cout << "no\n";
        }else if(n == 1) {
            cout << "yes\n";
        }else if(n == 2) {
            cout << (a[0] >= k && a[1] >= k ? "yes" : "no") << '\n';
        }else {
            flag = false;
            rep(i, 0, n - 2) {
                flag |= (((a[i] >= k) + (a[i + 1] >= k) + (a[i + 2] >= k)) >= 2);
            }
            cout << (flag ? "yes" : "no") << '\n';
        }
    }
}