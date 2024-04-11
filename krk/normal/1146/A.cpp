#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    int as = 0;
    for (int i = 0; i < s.length(); i++)
        as += s[i] == 'a';
    if (as > int(s.length()) - as) printf("%d\n", int(s.length()));
    else printf("%d\n", 2 * as - 1);
    return 0;
}