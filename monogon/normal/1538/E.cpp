
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

struct haha {
    ll len, cnt;
    string pre, suf;
    haha() {}
    haha(string s) {
        len = s.length();
        cnt = 0;
        rep(i, 0, len - 3) {
            if(s[i] == 'h' && s[i + 1] == 'a' && s[i + 2] == 'h' && s[i + 3] == 'a') cnt++;
        }
        pre = s.substr(0, 5);
        reverse(all(s));
        suf = s.substr(0, 5);
    }
    haha operator+(const haha &o) const {
        haha x;
        x.len = len + o.len;
        x.cnt = cnt + o.cnt +
            (suf.substr(0, 3) == "hah" && o.pre.substr(0, 1) == "a") + 
            (suf.substr(0, 2) == "ah" && o.pre.substr(0, 2) == "ha") +
            (suf.substr(0, 1) == "h" && o.pre.substr(0, 3) == "aha");
        x.pre = pre + o.pre.substr(0, max(0, 5 - (int) pre.length()));
        x.suf = o.suf + suf.substr(0, max(0, 5 - (int) o.suf.length()));
        return x;
    }
};

void solve() {
    int n;
    cin >> n;
    map<string, haha> h;
    ll last = 0;
    rep(i, 0, n) {
        string x, op, a, b;
        cin >> x >> op >> a;
        if(op == "=") {
            cin >> op >> b;
            h[x] = h[a] + h[b];
        }else {
            h[x] = haha(a);
        }
        last = h[x].cnt;
    }
    cout << last << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}