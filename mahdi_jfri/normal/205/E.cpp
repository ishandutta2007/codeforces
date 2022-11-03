#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ld sum[maxn][26] , rsum[maxn][26] , ans , k;
string a , b;
int main()
{
    cout << fixed << setprecision(10);
    int n;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 26; j++)
        {
            sum[i][j] = sum[i - 1][j] + (a[i] - 'A' == j ? i + 1 : 0);
        }
    for(int i = n - 1; i > -1; i--)
        for(int j = 0; j < 26; j++)
        {
            rsum[i][j] = rsum[i + 1][j] + (a[i] - 'A' == j? n - i : 0);
        }
    for(int i = 0; i < n; i++)
    {
        ans += rsum[i + 1][b[i] - 'A'] * (i + 1) + sum[i][b[i] - 'A'] * (n - i);
    }
    k = (double)n * (double)(n + 1) * (double)(2 * n + 1) / 6.0;
    cout << (long double)(ans) / (long double)k;
}