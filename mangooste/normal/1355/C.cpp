#include <algorithm>
#include <cassert>
#include <cmath>
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
 
#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const int N = 1e6 + 4;
int cnt[N], fen[N], suf[N + 1];
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int i = A; i <= B; i++)
        fen[i + B]++, fen[i + C + 1]--;
    for (int i = 0, sm = 0; i < N; i++) {
        sm += fen[i];
        cnt[i] = sm;
    }
    suf[N] = 0;
    for (int i = N - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + cnt[i];
    ll ans = 0;
    for (int i = C; i <= D; i++)
        ans += suf[i + 1];
    cout << ans << '\n';
}