
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

struct interactor {
    set<int> s;
    int n, x;
    interactor() {}
    interactor(int n, int x) : n(n), x(x) {
        rep(i, 1, n + 1) s.insert(i);
    }
    int query(char c, int a) {
        int ans = 0;
        for(int i = a; i <= n; i += a) {
            if(s.count(i) > 0) {
                ans++;
                if(c == 'B' && i != x) s.erase(i);
            }
        }
        return ans;
    }
};

//interactor I;

int ask(char ty, int a) {
    cout << ty << " " << a << endl;
    int ans;// = I.query(ty, a);
    cin >> ans;
    return ans;
}

const int sq = 320, K = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    vi p;
    rep(i, 2, n + 1) {
        if(prime[i]) {
            p.push_back(i);
            for(int j = 2 * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    int idx = lower_bound(all(p), sq) - p.begin();
    int pre = idx;
    int cnt = 0;
    int x = 1;
    int remain = n;
    rep(i, idx, sz(p)) {
        ask('B', p[i]);
        for(int j = p[i]; j <= n; j += p[i]) remain--;
        cnt++;
        if(cnt == K || i == sz(p) - 1) {
            if(ask('A', 1) > remain) {
                remain++;
                rep(j, pre, i + 1) {
                    if(ask('A', p[j]) > 0) {
                        x *= p[j];
                    }
                }
            }
            cnt = 0;
            pre = i + 1;
        }
    }
    rep(i, 0, idx) {
        ll pw = p[i];
        ask('B', p[i]);
        while(pw <= n && ask('A', pw) > 0) {
            pw *= p[i];
        }
        pw /= p[i];
        x *= pw;
    }
    cout << "C " << x << endl;
}