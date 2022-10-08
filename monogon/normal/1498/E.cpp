
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
    vi k(n + 1);
    rep(i, 1, n + 1) {
        cin >> k[i];
    }
    vector<array<int, 3>> ve;
    rep(i, 1, n + 1) rep(j, i + 1, n + 1) {
        ve.push_back({abs(k[i] - k[j]), i, j});
    }
    sort(all(ve), greater<>());
    for(auto &ar : ve) {
        int i = ar[1], j = ar[2];
        if(k[i] < k[j]) swap(i, j);
        cout << "? " << i << ' ' << j << endl;
        string ans;
        cin >> ans;
        if(ans == "Yes") {
            cout << "! " << i << ' ' << j << endl;
            return 0;
        }
    }
    cout << "! 0 0" << '\n';
}