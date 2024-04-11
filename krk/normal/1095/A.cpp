#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0, pnt = 1; i < n; i += pnt, pnt++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}