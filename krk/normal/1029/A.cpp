#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, k;
string t;
char res[Maxn];
int rlen;

int main()
{
    cin >> n >> k;
    cin >> t;
    fill(res, res + Maxn, '?');
    for (int i = 0; k > 0; i++) {
        bool ok = true;
        for (int j = 0; j < t.length() && ok; j++)
            ok = res[i + j] == '?' || res[i + j] == t[j];
        if (ok) {
            k--;
            for (int j = 0; j < t.length(); j++)
                res[i + j] = t[j];
        }
    }
    while (res[rlen] != '?') rlen++;
    res[rlen] = '\0';
    printf("%s\n", res);
    return 0;
}