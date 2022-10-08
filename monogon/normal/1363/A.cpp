
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1005;
int t, n, x;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        int e[2] = {0, 0};
        ll sum = 0;
        rep(i, 0, n) {
            cin >> a[i];
            e[a[i] & 1]++;
            sum += a[i];
        }
        if((x == n && sum % 2 == 0) || e[1] == 0 || (e[0] == 0 && x % 2 == 0)) {
            cout << "No\n";
        }else {
            cout << "Yes\n";
        }
    }
}