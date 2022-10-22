#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

string s, t;
int L[Maxn], R[Maxn];
int res;

int main()
{
    getline(cin, s);
    getline(cin, t);
    int pnt = 0; L[0] = -1;
    for (int i = 0; i < s.length(); i++)
        if (pnt < t.length() && s[i] == t[pnt]) {
            pnt++; L[pnt] = i;
        }
    pnt = 0; R[0] = int(s.length());
    for (int i = int(s.length()) - 1; i >= 0; i--)
        if (pnt < t.length() && s[i] == t[int(t.length()) - pnt - 1]) {
            pnt++; R[pnt] = i;
        }
    for (int i = 0; i <= t.length(); i++)
        res = max(res, R[int(t.length()) - i] - L[i] - 1);
    printf("%d\n", res);
    return 0;
}