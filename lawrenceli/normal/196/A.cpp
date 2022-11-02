#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100100;

int n, m;
char s[maxn], t[maxn];
vector<int> loc[200];

int main() {
    cin >> s;
    n = strlen(s);

    for (int i = 0; i < n; i++)
        loc[s[i]].push_back(i);

    for (int i = 0; i < n; ) {
        for (char c = 'z'; c >= 'a'; c--) {
            int p = lower_bound(loc[c].begin(), loc[c].end(), i) - loc[c].begin();
            if (p != loc[c].size()) {
                t[m++] = c;
                i = loc[c][p] + 1;
                break;
            }
        }
    }

    cout << t << '\n';
}