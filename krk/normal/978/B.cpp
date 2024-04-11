#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int res;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && s[i] == s[j]) j++;
        if (j - i >= 3 && s[i] == 'x')
            res += j - i - 2;
    }
    cout << res << endl;
    return 0;
}