#include <bits/stdc++.h>
using namespace std;

set <string> S = {"agc", "arc", "abc", "ahc"};

string s;
int x;

void Print(bool yes)
{
    printf(yes? "yes\n": "no\n");
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    assert(S.find(s) != S.end());
    scanf("%d", &x);
    if (s == "agc") Print(x >= 1200);
    else if (s == "arc") Print(x <= 2799);
    else if (s == "abc") Print(x <= 1999);
    else Print(true);
    return 0;
}