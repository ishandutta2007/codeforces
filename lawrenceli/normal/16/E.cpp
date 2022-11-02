#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

const int MAXN = 18;

int n;
vector<int> v[1<<MAXN];
double mat[MAXN][MAXN], p[1<<MAXN][MAXN], dp[1<<MAXN];

double calc(int x) {
    double& ret = dp[x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i=0; i<v[x].size(); i++)
        ret += p[x][i]*calc(x^1<<v[x][i]);
    return ret;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> mat[i][j];

    for (int i=0; i<1<<n; i++)
        for (int j=0; j<n; j++)
            if (i&1<<j)
                v[i].push_back(j);

    for (int i=0; i<1<<n; i++)
        if (__builtin_popcount(i) > 1) {
            int div = v[i].size()*(v[i].size()-1)/2;
            for (int j=0; j<v[i].size(); j++)
                for (int k=0; k<v[i].size(); k++)
                    p[i][k] += mat[v[i][j]][v[i][k]] / div;
        }

    for (int i=0; i<n; i++) {
        for (int j=0; j<1<<n; j++) dp[j] = -1;
        for (int j=0; j<n; j++)
            if (j == i) dp[1<<j] = 1;
            else dp[1<<j] = 0;
        cout << fixed << setprecision(10) << calc((1<<n)-1) << ' ';
    }
    return 0;
}