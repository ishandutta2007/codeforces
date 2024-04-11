
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
ll a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        if(b >= a) {
            cout << b << '\n';
        }else if((c - d) > 0) {
            cout << b + c * ((a - b + c - d - 1) / (c - d)) << '\n';
        }else {
            cout << "-1\n";
        }
    }
}