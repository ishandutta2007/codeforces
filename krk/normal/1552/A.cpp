#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s, t;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cin >> s;
        t = s;
        sort(t.begin(), t.end());
        int res = 0;
        for (int i = 0; i < s.length(); i++)
            res += s[i] != t[i];
        printf("%d\n", res);
    }
    return 0;
}