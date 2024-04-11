
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
        map<int, vi> ma;
        rep(i, 1, n + 1) {
            int a;
            cin >> a;
            ma[a].push_back(i);
        }
        for(auto &pa : ma) {
            if(pa.second.size() == 1) {
                cout << pa.second[0] << '\n';
                goto hell;
            }
        }
        cout << -1 << '\n';
        hell:;
    }
}