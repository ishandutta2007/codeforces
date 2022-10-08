
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

const int N = 1e5 + 5;
int n;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<ll> ve1, ve2;
    rep(i, 0, n) {
        cin >> a[i];
        if(i > 0) ve1.push_back(a[i] - a[i - 1]);
    }
    rep(i, 0, n) {
        cin >> b[i];
        if(i > 0) ve2.push_back(b[i] - b[i - 1]);
    }
    sort(all(ve1));
    sort(all(ve2));
    if(a[0] != b[0]) {
        cout << "No\n";
        return 0;
    }
    rep(i, 0, n - 1) {
        if(ve1[i] != ve2[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}