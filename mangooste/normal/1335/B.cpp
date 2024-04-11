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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        char free = 'a';
        for (int i = 0; i < b; i++)
            s.push_back(free++);
        for (int i = b; i < a; i++)
            s.push_back('a');
        for (int i = 0; i < n; i++)
            cout << s[i % a];
        cout << '\n';
    }
}