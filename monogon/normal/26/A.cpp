
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
    int cnt = 0;
    rep(i, 1, n + 1) {
        int x = i;
        int d = 0;
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                d++;
                while(x % j == 0) x /= j;
            }
        }
        d += (x > 1);
        if(d == 2) cnt++;
    }
    cout << cnt << '\n';
}