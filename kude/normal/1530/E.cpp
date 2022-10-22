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
        int hist[26] = {};
        string s;
        cin >> s;
        const int n = s.size();
        for(char c: s) {
            int x = c - 'a';
            hist[x]++;
        }
        int mn = n;
        rep(i, 26) if (hist[i]) chmin(mn, hist[i]);
        if (mn == n) {
            cout << s << '\n';
            continue;
        }
        if (mn == 1) {
            string t;
            rep(i, 26) if (hist[i] == 1) {
                t += 'a' + i;
                hist[i] = 0;
                break;
            }
            rep(i, 26) t.insert(t.end(), hist[i], 'a' + i);
            cout << t << '\n';
            continue;
        }
        assert(mn >= 2);
        int i1 = -1, i2 = -1, i3 = -1;
        rep(i, 26) if (hist[i]) {
            if (i1 == -1) i1 = i;
            else if (i2 == -1) i2 = i;
            else {
                i3 = i;
                break;
            }
        }
        int rest = n - hist[i1];
        if (hist[i1] - 2 <= rest) {
            string t;
            t += 'a' + i1;
            t += 'a' + i1;
            hist[i1] -= 2;
            while(hist[i1]) {
                while(hist[i2] == 0) i2++;
                t += 'a' + i2;
                hist[i2]--;
                t += 'a' + i1;
                hist[i1]--;
            }
            rep(i, 26) t.insert(t.end(), hist[i], 'a' + i);
            cout << t << '\n';
            continue;
        }
        if (i3 != -1) {
            string t;
            t += 'a' + i1;
            t += 'a' + i2;
            hist[i1]--, hist[i2]--;
            t.insert(t.end(), hist[i1], 'a' + i1);
            hist[i1] = 0;
            t += 'a' + i3;
            hist[i3]--;
            rep(i, 26) t.insert(t.end(), hist[i], 'a' + i);
            cout << t << '\n';
            continue;
        }
        string t;
        t += 'a' + i1;
        hist[i1]--;
        t.insert(t.end(), hist[i2], 'a' + i2);
        t.insert(t.end(), hist[i1], 'a' + i1);
        cout << t << '\n';
    }
}