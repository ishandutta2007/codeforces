#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

string s;
int ans;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    for (int i=0; i<s.length(); i++) {
        int cur = 1, j = i, pnt = i;
        for (; j < s.length(); j++) {
            if (s[j] == s[i] && ((j - pnt) & 1))
                cur ++, pnt = j;
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}