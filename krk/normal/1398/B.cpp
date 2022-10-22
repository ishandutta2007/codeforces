#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        vector <int> seq;
        for (int i = 0, j; i < s.length(); i = j) {
            j = i;
            while (j < s.length() && s[i] == s[j]) j++;
            if (s[i] == '1') seq.push_back(j - i);
        }
        sort(seq.rbegin(), seq.rend());
        int res = 0;
        for (int i = 0; i < seq.size(); i += 2)
            res += seq[i];
        printf("%d\n", res);
    }
    return 0;
}