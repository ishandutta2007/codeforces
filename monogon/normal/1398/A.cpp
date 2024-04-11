
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n);
        vector<pii> ve;
        rep(i, 0, n) {
            cin >> a[i];
            ve.emplace_back(a[i], i+1);
        }
        sort(all(ve));
        if(ve[0].first + ve[1].first <= ve[n - 1].first) {
            vector<int> b;
            b.push_back(ve[0].second);
            b.push_back(ve[1].second);
            b.push_back(ve[n - 1].second);
            sort(all(b));
            for(int x : b) cout << x << ' ';
            cout << '\n';
        }else {
            cout << "-1\n";
        }
    }
}