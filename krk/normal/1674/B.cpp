#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        int res = (s[0] - 'a') * 25;
        res += s[1] - 'a' + 1;
        if (s[0] < s[1]) res--;
        printf("%d\n", res);
    }
    return 0;
}