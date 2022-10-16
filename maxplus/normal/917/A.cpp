#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        int lo = 0, fr = 0, bad = 0;
        for (int j = i; j < s.size(); ++j) {
            lo += 2 * (s[j] == '(') - 1;
            fr += (s[j] == '?') - (lo < 0);
            lo = abs(lo);
            bad |= fr < 0;
            res += !bad && lo <= 0 && lo % 2 == 0;
        }
    }
    cout << res;
    return 0;
}