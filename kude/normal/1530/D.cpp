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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i], a[i]--;
        VI ord(n);
        iota(all(ord), 0);
        VI indeg(n);
        for(int x: a) indeg[x]++;
        sort(all(ord), [&](int i, int j) {return indeg[i] < indeg[j];});
        vector<bool> used(n);
        queue<int> others;
        int cnt = 0;
        VI b(n);
        for(int i: ord) {
            if (!used[a[i]]) {
                used[a[i]] = true;
                cnt++;
                b[i] = a[i];
            } else {
                b[i] = others.front(); others.pop();
            }
            if (indeg[i] == 0) others.push(i);
        }
        cout << cnt << '\n';
        rep(i, n) cout << b[i] + 1 << " \n"[i + 1 == n];
    }
}