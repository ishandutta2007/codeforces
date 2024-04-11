
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

void solve() {
    int n;
    cin >> n;
    int A = 0, B = 0;
    rep(i, 0, n) {
        int a;
        cin >> a;
        (a == 1 ? A : B)++;
    }
    rep(i, 0, A + 1) {
        int j = A + 2 * B - 2 * i;
        if(j % 4 == 0) {
            j /= 4;
            if(j >= 0 && j <= B) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}