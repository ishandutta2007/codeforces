#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

long long a[1111], f[1111][1111];
int n, m, k, from[1111][1111]; // 1 - ii and jj in pair, 2 - ii and jj + 1 in pair, 3 - jj and jj + 1 in pair

void findf(int ii, int jj)
{
    if (f[ii][jj] != 0) return;
    long long res = 0, val1 = 0, val2 = 0, val3 = 0;
    if (jj + 1 == n)
    {
        val1 = max(a[ii], a[jj]) + a[jj + 1];
        val2 = max(a[ii], a[jj + 1]) + a[jj];
        val3 = max(a[jj], a[jj + 1]) + a[ii];
        res = min(val1, min(val2, val3));
        f[ii][jj] = res;
        if (res == val1) from[ii][jj] = 1;
        if (res == val2) from[ii][jj] = 2;
        if (res == val3) from[ii][jj] = 3;
        return;
    }
    if (jj == n)
    {
        res = max(a[ii], a[jj]);
        f[ii][jj] = res;
        from[ii][jj] = 1;
        return;
    }
    findf(jj + 1, jj + 2);
    val1 = f[jj + 1][jj + 2] + max(a[ii], a[jj]);
    findf(jj, jj + 2);
    val2 = f[jj][jj + 2] + max(a[ii], a[jj + 1]);
    findf(ii, jj + 2);
    val3 = f[ii][jj + 2] + max(a[jj], a[jj + 1]);
    res = min(val1, min(val2, val3));
    f[ii][jj] = res;
    if (res == val1) from[ii][jj] = 1;
    if (res == val2) from[ii][jj] = 2;
    if (res == val3) from[ii][jj] = 3;
    return;
}

void repair(int ii, int jj)
{
    if (jj + 1 == n)
    {
        if (from[ii][jj] == 1)
        {
            cout << ii << " " << jj << endl << jj + 1;
            return;
        }
        if (from[ii][jj] == 2)
        {
            cout << ii << " " << jj + 1 << endl << jj;
            return;
        }
        if (from[ii][jj] == 3)
        {
            cout << jj << " " << jj + 1 << endl << ii;
            return;
        }
    }
    if (jj == n)
    {
        cout << ii << " " << jj << endl;
        return;
    }
    if (from[ii][jj] == 1)
    {
        cout << ii << " " << jj << endl;
        repair(jj + 1, jj + 2);
        return;
    }
    if (from[ii][jj] == 2)
    {
        cout << ii << " " << jj + 1 << endl;
        repair(jj, jj + 2);
        return;
    }
    if (from[ii][jj] == 3)
    {
        cout << jj << " " << jj + 1 << endl;
        repair(ii, jj + 2);
        return;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
    {
        cout << a[1] << endl << 1;
        return 0;
    }
    findf(1, 2);
    cout << f[1][2] << endl;
    repair(1,2);
    return 0;
}