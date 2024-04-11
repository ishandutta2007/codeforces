
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

const int N = 1e5 + 5;
int n;
int a[N], b[N], cnt[N], cnt2[N];

bool check(int k) {
    priority_queue<pair<int, int>> Q;
    rep(i, 1, n + 1) {
        cnt2[i] = cnt[i];
        if(cnt2[i] > 0) {
            Q.emplace(cnt2[i], i);
        }
    }
    rep(i, 0, n) {
        if(i - k - 1 >= 0 && cnt2[b[i - k - 1]] > 0) {
            Q.emplace(cnt2[b[i - k - 1]], b[i - k - 1]);
        }
        if(Q.empty()) return false;
        int x = Q.top().second; Q.pop();
        b[i] = x;
        cnt2[x]--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n;
        rep(i, 1, n + 1) cnt[i] = 0;
        rep(i, 0, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        // cout << check(3) << endl;
        // rep(i, 1, n + 1) {
        //     cout << check(i) << ' ';
        // }
        // cout << endl;
        int L = 1, R = n;
        while(L < R) {
            int m = (L + R) / 2;
            if(check(m)) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        cout << L-1 << '\n';
    }
}