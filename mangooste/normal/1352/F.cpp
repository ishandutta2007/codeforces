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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        string ans = "";
        if (a == 0) {
            if (b % 2 == 0) {
                for (int i = 0; i < b / 2; i++) {
                    ans.pb('1');
                    ans.pb('0');
                }
                ans.pb('1');
                for (int i = 0; i < c; i++)
                    ans.pb('1');
            } else {
                ans.pb('0');
                for (int i = 0; i < b / 2; i++) {
                    ans.pb('1');
                    ans.pb('0');
                }
                ans.pb('1');
                for (int i = 0; i < c; i++)
                    ans.pb('1');
            }
        } else {
            if (b == 0) {
                for (int i = 0; i < a + 1; i++)
                    ans.pb('0');
            } else if (b % 2 == 0) {
                ans.pb('1');
                ans.pb('0');
                for (int i = 0; i < a; i++)
                    ans.pb('0');
                for (int i = 0; i < b / 2 - 1; i++) {
                    ans.pb('1');
                    ans.pb('0');
                }
                ans.pb('1');
                for (int i = 0; i < c; i++)
                    ans.pb('1');
            } else {
                for (int i = 0; i < a; i++)
                    ans.pb('0');
                ans.pb('0');
                for (int i = 0; i < b / 2; i++) {
                    ans.pb('1');
                    ans.pb('0');
                }
                ans.pb('1');
                for (int i = 0; i < c; i++)
                    ans.pb('1');
            }
        }
        cout << ans << '\n';
    }
}