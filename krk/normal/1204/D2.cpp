#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

char str[Maxn];
int slen;
int best[Maxn];
int dp[Maxn];
char res[Maxn];

int main()
{
    scanf("%s", str);
    slen = strlen(str);
    vector <int> seq;
    for (int i = slen - 1; i >= 0; i--) {
        int let = str[i] - '0';
        let = 1 - let;
        int ind = upper_bound(seq.begin(), seq.end(), let) - seq.begin();
        if (ind < seq.size()) seq[ind] = let;
        else seq.push_back(let);
        best[i] = seq.size();
    }
    for (int i = slen - 1; i >= 0; i--)
        if (best[i] > best[i + 1]) res[i] = '0';
        else res[i] = '1';
    res[slen] = '\0';
    printf("%s\n", res);
    return 0;
}