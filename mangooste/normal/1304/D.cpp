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

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

int n;
string s;

void get_min() {
    int free = 1;
    int pos = n - 1;
    vector<int> ans(n, -1);
    while (pos > 0) {
        if (s[pos - 1] == '>') {
            ans[pos--] = free++;
            continue;
        }
        int left = pos;
        while (left > 0 && s[left - 1] == '<')
            left--;
        for (int i = left; i <= pos; i++)
            ans[i] = free++;
        pos = left - 1;
    }
    if (ans[0] == -1)
        ans[0] = free;
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

void get_max() {
    int free = n;
    int pos = n - 1;
    vector<int> ans(n, -1);
    while (pos > 0) {
        if (s[pos - 1] == '<') {
            ans[pos--] = free--;
            continue;
        }
        int left = pos;
        while (left > 0 && s[left - 1] == '>')
            left--;
        for (int i = left; i <= pos; i++)
            ans[i] = free--;
        pos = left - 1;
    }
    if (ans[0] == -1)
        ans[0] = free;
    for (int i : ans) 
        cout << i << ' ';
    cout << '\n';
}

void solve() {
    cin >> n >> s;
    get_min();
    get_max();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) 
        solve();
}