#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxm = 1000001;

vector <int> dvs[Maxm];
int dp[Maxm];
int res;

int main()
{
    for (int i = 1; i < Maxm; i++)
        for (int j = i; j < Maxm; j += i)
            dvs[j].push_back(i);
    dp[0] = 1;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        for (int j = int(dvs[a].size()) - 1; j >= 0; j--) {
            int d = dvs[a][j];
            int add = dp[d - 1];
            dp[d] = (dp[d] + add) % mod;
            res = (res + add) % mod;
        }
    }
    cout << res << endl;
    return 0;
}