#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

long C[200000][100] = {{0}};
bool ex_C[200000][100] = {{0}};

int cal_C(int m, int n)
{
    if (ex_C[m][n])
        return C[m][n];
    else if (m < n)
        return 0;
    else if (m == n || n == 0)
        return 1;
    else
    {
        C[m][n] = (cal_C(m - 1, n) % 1000000007 + cal_C(m - 1, n - 1) % 1000000007) % 1000000007;
        ex_C[m][n] = true;
        return C[m][n];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a;
        ll n, r = 0, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.emplace_back(tmp);
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++){
            r += cal_C((lower_bound(a.begin(), a.end(), a[i] + k + 1) - a.begin()) - i - 1, m - 1);
            r %= 1000000007;
        }
        cout << r << '\n';
    }
}