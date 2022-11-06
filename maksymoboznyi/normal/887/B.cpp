#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 1e6;
int n, a[10][10], is[10][10];
bool can[1001];
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
        {
            cin >> a[i][j];
        }
    for (int j = 0; j < 6; j++)
        for (int j1 = 0; j1 < 6; j1++)
            for (int j2 = 0; j2 < 6; j2++)
            {
                if (n == 1)
                    can[a[0][j]] = 1;
                if (n == 2)
                {
                    can[a[0][j]] = 1;
                    can[a[1][j1]] = 1;
                    can[a[0][j]*10+a[1][j1]] = 1;
                    can[a[1][j1]*10+a[0][j]] = 1;
                }
                if (n == 3)
                {
                    can[a[0][j]] = 1;
                    can[a[1][j1]] = 1;
                    can[a[2][j2]] = 1;

                    can[a[0][j]*10+a[1][j1]] = 1;
                    can[a[1][j1]*10+a[0][j]] = 1;

                    can[a[0][j]*10+a[2][j2]] = 1;
                    can[a[2][j2]*10+a[0][j]] = 1;

                    can[a[2][j2]*10+a[1][j1]] = 1;
                    can[a[1][j1]*10+a[2][j2]] = 1;


                    can[a[0][j]*100+a[1][j1]*10+a[2][j2]]=1;
                    can[a[0][j]*100+a[2][j2]*10+a[1][j1]]=1;

                    can[a[1][j1]*100+a[0][j]*10+a[2][j2]]=1;
                    can[a[1][j1]*100+a[2][j2]*10+a[0][j]]=1;

                    can[a[2][j2]*100+a[0][j]*10+a[1][j1]]=1;
                    can[a[2][j2]*100+a[1][j1]*10+a[0][j]]=1;
                }
            }
    for (int x = 1; x <= 1000; x++)
        if (!can[x])
    {
        cout << x-1;
        return 0;
    }
    return 0;
}