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
    int n, S;
    cin >> n >> S;
    if (S < n * 2)
        return cout << "No\n", 0;
    cout << "Yes\n";
    for (int i = 0; i < n - 1; i++)
        cout << "2 ";
    cout << S - 2 * (n - 1) << '\n';
    cout << "1\n";
}