#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

string s;
char A[Maxn];
int alen;
char res[Maxn];
int rlen;

int main()
{
    cin >> s;
    int l = 0, r = int(s.length()) - 1;
    while (r - l + 1 >= 4) {
        bool found = false;
        for (int i = l; i <= l + 1 && !found; i++)
            for (int j = r - 1; j <= r && !found; j++)
                if (s[i] == s[j]) {
                    found = true;
                    A[alen++] = s[i];
                }
        l += 2; r -= 2;
    }
    for (int i = 0; i < alen; i++)
        res[rlen++] = A[i];
    if (l <= r)
        res[rlen++] = s[l];
    for (int i = alen - 1; i >= 0; i--)
        res[rlen++] = A[i];
    res[rlen] = '\0';
    printf("%s\n", res);
    return 0;
}