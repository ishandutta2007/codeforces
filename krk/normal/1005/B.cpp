#include <bits/stdc++.h>
using namespace std;

string s, t;

int main()
{
    cin >> s;
    cin >> t;
    int res = 0;
    while (res < s.length() && res < t.length() &&
           s[int(s.length()) - 1 - res] == t[int(t.length()) - 1 - res])
        res++;
    printf("%d\n", int(s.length()) + int(t.length()) - 2 * res);
    return 0;
}