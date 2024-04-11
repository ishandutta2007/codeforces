#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
ll res;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if ((s[i] - '0') % 2 == 0)
            res += i + 1;
    cout << res << endl;
    return 0;
}