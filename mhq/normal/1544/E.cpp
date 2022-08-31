#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(26);
        for (char& c : s) cnt[c - 'a']++;
        sort(s.begin(), s.end());
        if (s[0] == s[n - 1]) {
            cout << s << '\n';
            continue;
        }
        int ind = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1) {
                ind = i;
                break;
            }
        }
        if (ind != -1) {
            cnt[ind]--;
            cout << (char)(ind + 'a');
            for (int z = 0; z < 26; z++) {
                for (int x = 0; x < cnt[z]; x++) cout << (char)(z + 'a');
            }
            cout << '\n';
            continue;
        }
        assert(n > 2);
        int a = -1;
        int b = -1;
        for (int x = 0; x < 26; x++) {
            if (cnt[x] == 0) continue;
            if (a != -1) break;
            for (int y = 0; y < 26; y++) {
                if (cnt[y] == 0) continue;
                if (a != -1) break;
                int other;
                if (x == y) other = n - cnt[x];
                else other = n - cnt[x] - cnt[y];
                if (x == y) {
                    if (other >= cnt[x] - 2) {
                        a = x;
                        b = y;
                        break;
                    }
                }
                else {
                    a = x;
                    b = y;
                    break;
                }
            }
        }
        assert(a != -1);
        string ans;
        ans += (char)('a' + a);
        ans += (char)('a' + b);
        int other;
        if (a == b) other = n - cnt[a];
        else other = n - cnt[a] - cnt[b];
        cnt[a]--;
        cnt[b]--;
        for (int z = 0; z < n - 2; z++) {
            int he = -1;
            for (int u = 0; u < 26; u++) {
                if (cnt[u] == 0) continue;
                if (ans.back() == (char)('a' + a) && u == b) continue;
                int nother = other;
                int ncnta = cnt[a];
                int ncntb = cnt[b];
                if (u == a) ncnta--;
                if (u == b) ncntb--;
                if (u != a && u != b) nother--;
                if (a == b) {
                    if (u != a) {
                        if (nother >= ncnta - 1) {
                            he = u;
                            break;
                        }
                    }
                    else {
                        if (nother >= ncnta) {
                            he = u;
                            break;
                        }
                    }
                }
                else {
                    if (u != a) {
                        he = u;
                        break;
                    }
                    if (nother != 0 || ncntb == 0) {
                        he = u;
                        break;
                    }
                }
            }
            assert(he != -1);
            ans += (char)('a' + he);
            if (he != a && he != b) {
                other--;
                cnt[he]--;
            }
            if (a == b) {
                if (he == a) cnt[a]--;
            }
            else {
                if (he == a) cnt[a]--;
                if (he == b) cnt[b]--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}