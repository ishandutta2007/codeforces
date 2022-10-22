#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int now = 0;
        VI ls;
        rep(i, n) {
            if (s[i] == 'L') now++;
            else {
                ls.push_back(now);
                now = 0;
            }
        }
        ls.push_back(now);

        if (ls.size() == 1) {
            if (k == 0) cout << 0 << endl;
            else cout << (k-1) * 2 + 1 << endl;
            continue;
        }
        int sz = ls.size();
        //rep(i, sz) cout << ls[i] << " \n"[i == sz-1];
        int score = sz - 1;
        //cout << score << endl;
        priority_queue<int, VI, greater<int>> q;
        for(int i = 1; i < sz - 1; i++) {
            if (ls[i] == 0) score++;
            else q.push(ls[i]);
        }
        int edge = ls.back() + ls[0];
        while(!q.empty() && q.top() <= k) {
            score += q.top() * 2 + 1;
            k -= q.top(); q.pop();
        }
        int rem = 0;
        while(!q.empty()) {
            rem += q.top(); q.pop();
        }
        rem += edge;
        chmin(k, rem);
        score += k * 2;
        cout << score << endl;
    }
}