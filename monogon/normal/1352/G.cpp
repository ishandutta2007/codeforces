
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

int t, n;

// 2 4 6 .. n (n - 3) (n - 1) (n - 5) ...

// 2 4 6 .. (n - 3) (n - 1) (n - 4) n (n - 2) (n - 6)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        if(n <= 3) {
            cout << "-1\n";
            continue;
        }
        if(n % 2 == 0) {
            int x = 2;
            do {
                cout << x << ' ';
                x += 2;
            }while(x <= n);
            x = n - 1;
            cout << x - 2 << ' ' << x << ' ';
            x -= 4;
            while(x > 0) {
                cout << x << ' ';
                x -= 2;
            }
        }else {
            int x = 2;
            do {
                cout << x << ' ';
                x += 2;
            }while(x <= n - 1);
            cout << (n - 4) << ' ' << n << ' ' << (n - 2) << ' ';
            x = n - 6;
            while(x > 0) {
                cout << x << ' ';
                x -= 2;
            }
        }
        cout << '\n';
    }
}