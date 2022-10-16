#include <bits/stdc++.h>

using namespace std;

map<string, int> a;
string s1, s2;

int main()
{
    int n, ans = 0;
    char c;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        s1 = "";
        while ((c = getchar()) != ' ')    s1 += tolower(c);
        cin >> s2;
        getchar();
        s2 = "";
        while ((c = getchar()) != '\n')   s2 += tolower(c);
        ans = max(ans, a[s1] = a[s2] + 1);
    }
    cout << ans + 1;
    return 0;
}