#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int n, k;
string s;
int got[Maxl];

int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j]) j++;
        got[s[i] - 'a'] += (j - i) / k;
    }
    int mx = 0;
    for (int i = 0; i < Maxl; i++)
        mx = max(mx, got[i]);
    printf("%d\n", mx);
    return 0;
}