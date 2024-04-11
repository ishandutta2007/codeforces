#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 3;
typedef bitset < maxN > bs;
bs T[26];
bs S[26];
int p[26];
bs nT[26];
int prv[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 26; i++) {
        cin >> p[i];
        p[i]--;
        prv[p[i]] = i;
    }
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < t.size(); i++) {
        T[t[i] - 'a'][i] = true;
    }
    for (int j = 0; j < 26; j++) {
        nT[j] = T[j] | (T[p[j]]);
    }
    bs ans;
    for (int i = 0; i + s.size() - 1 <= t.size(); i++) {
        ans[i] = true;
    }
    for (int i = 0; i < s.size(); i++) {
        ans &= (nT[s[i] - 'a'] >> i);
    }
    for (int i = 0; i + s.size() - 1 < t.size(); i++) {
        cout << ans[i];
    }
    return 0;
}