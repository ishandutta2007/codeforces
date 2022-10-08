
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
    string a, b;
    cin >> n >> a >> b;
    int cnt = 0;
    rep(i, 0, n) {
        if(i + 1 < n && (a[i] != b[i]) && (a[i + 1] != b[i + 1]) && (a[i] != a[i + 1])) {
            swap(a[i], a[i + 1]);
            cnt++;
        }
        else if(a[i] != b[i]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}