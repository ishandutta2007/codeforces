
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
    int n, m;
    cin >> n >> m;
    map<pii, char> ma;
    int aa = 0;
    ll ab = 0;
    while(m--) {
        char ty;
        cin >> ty;
        if(ty == '+') {
            int u, v; char c;
            cin >> u >> v >> c;
            ma[{u, v}] = c;
            if(ma.count({v, u}) && ma[{v, u}] == c) {
                aa++;
            }
            if(ma.count({v, u})) {
                ab++;
            }
        }else if(ty == '-') {
            int u, v;
            cin >> u >> v;
            if(ma.count({v, u}) && ma[{v, u}] == ma[{u, v}]) {
                aa--;
            }
            if(ma.count({v, u})) {
                ab--;
            }
            ma.erase({u, v});
        }else if(ty == '?') {
            int k; cin >> k;
            if(aa > 0) {
                cout << "YES\n";
            }else if(k % 2 == 1 && ab > 0) {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
    }
}