
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
int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if((k % 2 == 0 && n % 2 == 1) || (k % 2 == 1 && n % 2 == 1 && k > n) || (n % 2 == 0 && k % 2 == 1 && 2 * k > n) || (n % 2 == 0 && k % 2 == 0 && k > n)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(n % 2 == 0) {
            if(k % 2 == 1) {
                cout << (n - 2 * (k - 1)) << ' ';
                k--;
                while(k--) {
                    cout << "2 ";
                }
            }else {
                cout << (n - k + 1) << ' ';
                k--;
                while(k--) {
                    cout << "1 ";
                }
            }
            cout << '\n';
        }else {
            cout << (n - k + 1) << ' ';
            k--;
            while(k--) {
                cout << "1 ";
            }
            cout << '\n';
        }
    }
}