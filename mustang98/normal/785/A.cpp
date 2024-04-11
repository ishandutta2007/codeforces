#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    int n;
    cin >> n;
    char s[100];
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        if (s[0] == 'T') ans += 4;
        else if (s[0] == 'C') ans += 6;
        else if (s[0] == 'O') ans += 8;
        else if (s[0] == 'D') ans += 12;
        else if (s[0] == 'I') ans += 20;
    }
    cout << ans;
    return 0;
}