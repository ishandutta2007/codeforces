#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    int n; cin >> n;
    cin >> s;
    int mn = 0, res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') res++;
        else res--;
        mn = min(mn, res);
    }
    printf("%s\n", mn >= -1 && res == 0? "Yes": "No");
    return 0;
}