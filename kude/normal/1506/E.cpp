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
bool used[200100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI p(n);
        rep(i, n) cin >> p[i], p[i];
        {
            priority_queue<int, VI, greater<int>> q;
            rep(i, n + 10) used[i] = false;
            int nxt = 1;
            rep(i, n) {
                while(nxt <= p[i]) q.push(nxt++);
                if (!used[p[i]]) {
                    used[p[i]] = true;
                    cout << p[i] << " \n"[i + 1 == n];
                    continue;
                }
                int x = q.top(); q.pop();
                while(used[x]) {
                    x = q.top(); q.pop();
                }
                used[x] = true;
                cout << x << " \n"[i + 1 == n];
            }
        }
        {
            priority_queue<int> q;
            rep(i, n + 10) used[i] = false;
            int nxt = 1;
            rep(i, n) {
                while(nxt <= p[i]) q.push(nxt++);
                if (!used[p[i]]) {
                    used[p[i]] = true;
                    cout << p[i] << " \n"[i + 1 == n];
                    continue;
                }
                int x = q.top(); q.pop();
                while(used[x]) {
                    x = q.top(); q.pop();
                }
                used[x] = true;
                cout << x << " \n"[i + 1 == n];
            }
        }
    }
}