#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Maxd = 10;
const string digs[Maxd] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int n, k;
string s[Maxn];
bool dp[Maxn][Maxn];

int Get(const string &a, const string &b)
{
    int res = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == '1')
            if (b[i] == '0') return -1;
            else ;
        else if (b[i] == '1') res++;
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < Maxd; j++) {
            int add = Get(s[i], digs[j]);
            if (add == -1) continue;
            for (int j = add; j <= k; j++)
                dp[i][j] |= dp[i + 1][j - add];
        }
    if (!dp[0][k]) printf("-1\n");
    else {
        for (int i = 0; i < n; i++)
            for (int j = Maxd - 1; j >= 0; j--) {
                int add = Get(s[i], digs[j]);
                if (add == -1) continue;
                if (add <= k && dp[i + 1][k - add]) {
                    printf("%d", j);
                    k -= add;
                    break;
                }
            }
        printf("\n");
    }
    return 0;
}