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
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        rep(i, n) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
        }
        if (cnt1 % 2 == 0 && cnt0 % 2 == 0) {
            int m = cnt1 / 2;
            string a, b;
            int now_a = 0, now_b = 0;
            bool ok = true;
            for(int c: s) {
                if (c == '1') {
                    if (m) {
                        m--;
                        a.push_back('(');
                        b.push_back('(');
                        now_a++, now_b++;
                    } else {
                        a.push_back(')');
                        b.push_back(')');
                        now_a--, now_b--;
                    }
                } else {
                    if (now_a == now_b) {
                        a.push_back('(');
                        b.push_back(')');
                        now_a++, now_b--;
                    } else {
                        a.push_back(')');
                        b.push_back('(');
                        now_a--, now_b++;
                    }
                }
                if (now_a < 0 || now_b < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "YES\n";
                cout << a << '\n';
                cout << b << '\n';
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}