#include <bits/stdc++.h>
using namespace std;

int T;
string a, b;

bool Check(string a, string b)
{
    sort(a.begin(), a.end());
    for (int i = 0; i + int(a.length()) <= int(b.length()); i++) {
        string c = b.substr(i, int(a.length()));
        sort(c.begin(), c.end());
        if (a == c) return true;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> a;
        cin >> b;
        if (Check(a, b))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}