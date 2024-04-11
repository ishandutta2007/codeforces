
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s;
        vector<int> v;
        rep(i, 0, 2 * n) {
            int p;
            cin >> p;
            if(!s.count(p)) {
                s.insert(p);
                v.push_back(p);
            }
        }
        for(int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}