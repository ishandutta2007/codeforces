#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int tower[200000];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        cout << "YES\n";
        int n, m, x;
        cin >> n >> m >> x;
        rep(i, m) tower[i] = 0;
        auto cmp = [&](int i, int j) {return tower[i] > tower[j];};
        priority_queue<int, VI, decltype(cmp)> q(cmp);
        rep(i, m) q.push(i);
        rep(i, n) {
            int h;
            cin >> h;
            int p = q.top(); q.pop();
            cout << p + 1 << " \n"[i + 1 == n];
            tower[p] += h;
            q.push(p);
        }
    }
}