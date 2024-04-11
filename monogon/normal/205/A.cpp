
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
    vector<pii> a(n);
    rep(i, 0, n) {
        int x; cin >> x;
        a[i] = {x, i + 1};
    }
    sort(all(a));
    if(a[0].first == a[1].first) {
        cout << "Still Rozdil\n";
    }
    else {
        cout << a[0].second << '\n';
    }
}