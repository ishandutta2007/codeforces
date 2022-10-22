#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

char str[Maxn];
int slen;
int dp[Maxn];
vector <ii> my[Maxn], S;
int res;

int main()
{
    scanf("%s", str);
    slen = strlen(str);
    int fir = 0;
    while (fir < slen && str[fir] == '0') fir++;
    if (fir >= slen) { printf("%d\n", slen); return 0; }
    int lst = slen - 1;
    while (str[lst] == '0') lst--;
    S.push_back(ii(slen - 1 - lst, slen));
    dp[fir] = fir + 1;
    for (int i = slen - 1; i >= fir; i--) if (str[i] == '1') {
        my[i] = S;
        if (i > fir) {
            int j = i - 1;
            while (str[j] == '0') j--;
            int len = i - j - 1;
            while (!S.empty() && S.back().first <= len) S.pop_back();
            S.push_back(ii(len, i));
        }
    }
    for (int i = fir; i <= lst; i++) if (str[i] == '1') {
        int ind = my[i].back().second;
        int was = my[i].back().first;
        dp[ind] = (dp[ind] + ll(my[i].back().first + 1) * dp[i]) % mod;
        for (int j = int(my[i].size()) - 2; j >= 0; j--) {
            int cur = my[i][j].first;
            ind = my[i][j].second;
            dp[ind] = (dp[ind] + ll(cur - was) * dp[i]) % mod;
            was = cur;
        }
        res = (res + ll(slen - lst) * dp[i]) % mod;
    }
    printf("%d\n", res);
    return 0;
}