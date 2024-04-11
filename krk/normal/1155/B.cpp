#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
string s;
bool tk[Maxn];

int main()
{
    cin >> n;
    cin >> s;
    int my = (n - 11) / 2;
    for (int i = 0; i < s.length() && my > 0; i++)
        if (s[i] != '8') { tk[i] = true; my--; }
    int cl = 0;
    for (int i = 0; i < s.length(); i++) if (!tk[i])
        if (s[i] == '8') cl++;
        else break;
    if (cl <= (n - 11) / 2) printf("NO\n");
    else printf("YES\n");
    return 0;
}