#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    string a;
    while (cin >> a)
    if (s[0] == a[0] || s[1] == a[1]) {
            printf("YES\n"); return 0; }
    cout << "NO" << endl;
    return 0;
}