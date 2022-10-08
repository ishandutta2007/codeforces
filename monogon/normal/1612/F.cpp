
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
    int n, m, q;
    cin >> n >> m >> q;
    set<pii> se;
    while(q--) {
        int a, b;
        cin >> a >> b;
        se.insert({a, b});
    }
    vector<pii> A, B;
    A.push_back({1, 1});
    int step = 0;
    vi mxA(n + 1), mxB(m + 1);
    mxA[1] = mxB[1] = 1;
    while(true) {
        step++;
        B.clear();
        for(auto &pa : A) {
            int x, y;
            tie(x, y) = pa;
            int power = x + y + se.count(pa);
            B.push_back({x, min(power, m)});
            B.push_back({min(power, n), y});
        }
        sort(all(B));
        B.erase(unique(all(B)), B.end());
        for(auto &pa : B) {
            mxA[pa.first] = max(mxA[pa.first], pa.second);
            mxB[pa.second] = max(mxB[pa.second], pa.first);
        }
        int num = 0;
        rep(i, 0, sz(B)) {
            if(mxA[B[i].first] != B[i].second || mxB[B[i].second] != B[i].first) {
                num++;
            }else {
                B[i - num] = B[i];
            }
        }
        B.erase(B.end() - num, B.end());
        // for(auto &pa : B) { 
        //     cout << "(" << pa.first << ' ' << pa.second << ") ";
        // }
        // cout << '\n';
        if(mxA[n] == m) break;
        A.swap(B);
    }
    cout << step << '\n';
}