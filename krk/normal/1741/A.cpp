#include <bits/stdc++.h>
using namespace std;

int T;
string a;
string b;

int Get(const string &s)
{
    int st = 0;
    if (s[int(s.length()) - 1] == 'S') st = -1;
    else if (s[int(s.length()) - 1] == 'L') st = 1;
    return int(s.length()) * st;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> a;
        cin >> b;
        int ra = Get(a), rb = Get(b);
        if (ra > rb) printf(">\n");
        else if (ra < rb) printf("<\n");
        else printf("=\n");
    }
    return 0;
}