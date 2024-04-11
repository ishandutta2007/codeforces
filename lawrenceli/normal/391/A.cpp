#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    string s; cin >> s;
    int ans = 0;
    for (int i=0; i<s.length(); ) {
        int j = i;
        for (; j<s.length() && s[j] == s[i]; j++);
        if ((j - i) % 2 == 0) ans++;
        i = j;
    }

    cout << ans << endl;
    return 0;
}