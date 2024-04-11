#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        int res1 = -1, res2 = -1;
        for (int i = 0; i + 1 < n; i++)
            if (s[i] != s[i + 1]) {
                res1 = i + 1, res2 = i + 2;
                break;
            }
        cout << res1 << " " << res2 << endl;
    }
    return 0;
}