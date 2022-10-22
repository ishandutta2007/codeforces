#include <bits/stdc++.h>
using namespace std;

string s;
int res;

int main()
{
    cin >> s;
    int i;
    for (i = int(s.length()) - 1; i > 0; i -= 2)
        res++;
    if (i == 0) {
        bool was = false;
        for (int j = 1; j < s.length(); j++)
            if (s[j] == '1') was = true;
        res += was;
    }
    cout << res << endl;
    return 0;
}