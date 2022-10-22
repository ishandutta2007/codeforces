#include <bits/stdc++.h>
using namespace std;

int t;
int n;
string s;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cin >> s;
        int res = n;
        for (int i = 0; i < s.length(); i++) if (s[i] == '1')
            res = max(res, 2 * max(i + 1, int(s.length()) - i));
        printf("%d\n", res);
    }
    return 0;
}