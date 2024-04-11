#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 11;
const int Maxm = 20;
const int Maxb = 61;

int T;
char str[Maxm];
int slen;
string my[Maxb];
int dp[Maxn][Maxm];

string toString(ll x)
{
    stringstream ss; ss << x;
    string s; ss >> s;
    return s;
}

int Solve(int b)
{
    int sav = 0;
    for (int i = 0; i < slen && sav < my[b].length(); i++)
        if (str[i] == my[b][sav]) sav++;
    return slen + my[b].length() - 2 * sav;
}

int main()
{
    for (int i = 0; i < Maxb; i++)
        my[i] = toString(1ll << ll(i));
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        int res = Solve(0);
        for (int i = 1; i < Maxb; i++)
            res = min(res, Solve(i));
        printf("%d\n", res);
    }
    return 0;
}