#include <bits/stdc++.h>
using namespace std;

int t;
int n;
string s;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int pnt = 0;
        while (pnt < s.length() && s[pnt] != '8') pnt++;
        if (int(s.length()) - 1 - pnt >= 10) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}