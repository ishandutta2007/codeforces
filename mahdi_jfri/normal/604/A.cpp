#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define find findd
int m[10];
int res = 0;
int wa[10];
int a[10] = {500, 1000, 1500, 2000, 2500};
int main()
{
    cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4] >> wa[0] >> wa[1] >> wa[2] >> wa[3] >> wa[4];
    for(int i = 0; i < 5; i++)
    {
        res += max(3 * a[i] / 10, a[i] - ((a[i] * m[i]) / 250) - (50 * wa[i]));
    }
    int c , d;
    cin >> c >> d;
    cout << res + c * 100 - (50 * d);
}