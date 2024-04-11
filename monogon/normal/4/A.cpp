
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << ([&](int n) {
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= n; j++) {
                bool ieven = false, jeven = false;
                for(int k = 1; k <= n; k++) {
                    if(k * 2 == i) {
                        ieven = true;
                    }
                }
                for(int k = 1; k <= n; k++) {
                    if(k * 2 == j) {
                        jeven = true;
                    }
                }
                if(ieven && jeven) {
                    int cnt = 0;
                    for(int k = 0; k < i; k++) {
                        cnt += 1;
                    }
                    for(int k = 0; k < j; k++) {
                        cnt += 1;
                    }
                    if(cnt == n) {
                        return true;
                    }
                }
            }
        }
        return false;
    }(n) ? "YES" : "NO") << '\n';
}