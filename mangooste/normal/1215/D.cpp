#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
inline void GG(bool chk = false) {
    cout << (chk ? "Monocarp\n" : "Bicarp\n");
    exit(0);
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sm_lft = 0, sm_rgt = 0;
    int cnt_lft = 0, cnt_rgt = 0; 
    for (int i = 0; i < n / 2; i++)
        if (s[i] != '?')
            sm_lft += s[i] - '0';
        else
            cnt_lft++;
    for (int i = n / 2; i < n; i++)
        if (s[i] != '?')
            sm_rgt += s[i] - '0';
        else
            cnt_rgt++;
    GG(2 * sm_lft + 9 * cnt_lft != 2 * sm_rgt + 9 * cnt_rgt);
}