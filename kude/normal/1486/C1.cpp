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

int query(int l, int r) {
    cout << "? " << l + 1 << ' ' << r << endl;
    int p;
    cin >> p;
    return p - 1;
}

void answer(int p) {
    cout << "! " << p + 1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p2 = query(0, n);
    int l = 0, r = n; // ans is in [l, r)
    while(r - l > 1) {
        int c = r + l >> 1;
        bool in_left;
        if (c <= p2) {
            int cr = max(r, p2 + 1);
            if (cr - c >= 2) {
                int t = query(c, max(r, p2 + 1));
                in_left = t != p2;
            } else {
                in_left = true;
            }
        } else {
            int cl = min(l, p2);
            if (c - cl >= 2) {
                int t = query(min(l, p2), c);
                in_left = t == p2;
            } else {
                in_left = false;
            }
        }
        if (in_left) r = c;
        else l = c;
    }
    answer(l);
}