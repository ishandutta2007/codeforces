#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        map <char, int> M;
        for (int i = 0; i < s.length(); i++)
            M[s[i]]++;
        int sam = 0, dif = 0;
        for (auto it: M)
            if (it.second >= 2) sam++;
            else dif++;
        printf("%d\n", sam + dif / 2);
    }
    return 0;
}