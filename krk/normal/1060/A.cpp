#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int res;

int main()
{
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '8') cnt++;
    for (int i = 0; i <= cnt; i++)
        res = max(res, min(i, (n - i) / 10));
    printf("%d\n", res);
    return 0;
}