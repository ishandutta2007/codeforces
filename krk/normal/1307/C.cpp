#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 26;

string s;
ll freq[Maxl];
ll res;

ll Solve(char a, char b)
{
    ll was = 0, res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == b) res += was;
        if (s[i] == a) was++;
    }
    return res;
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        res = max(res, freq[s[i] - 'a']);
    }
    for (char a = 'a'; a <= 'z'; a++)
        for (char b = 'a'; b <= 'z'; b++)
            res = max(res, Solve(a, b));
    printf("%I64d\n", res);
    return 0;
}