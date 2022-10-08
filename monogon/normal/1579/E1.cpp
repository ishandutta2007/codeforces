
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

void solve() {
    int n;
    cin >> n;
    deque<int> Q;
    rep(i, 0, n) {
        int x;
        cin >> x;
        if(Q.empty() || x <= Q[0]) {
            Q.push_front(x);
        }else {
            Q.push_back(x);
        }
    }
    rep(i, 0, n) {
        cout << Q[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}