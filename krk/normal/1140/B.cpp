#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    int t; scanf("%d", &t);
    while (t--) {
        int n; cin >> n;
        cin >> s;
        int a = 0;
        while (a < s.length() && s[a] == '<') a++;
        int b = 0;
        while (b < s.length() && s[int(s.length()) - 1 - b] == '>') b++;
        printf("%d\n", min(a, b));
    }
    return 0;
}