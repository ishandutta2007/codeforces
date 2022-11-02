#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;
const int N = 100 * 1000 + 10;

int dpSmall[N];
int dpEq[N];
string s;
int a[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    fill(dpSmall, dpSmall + n + 1, -INF);
    fill(dpEq, dpEq + n + 1, -INF);
    dpEq[n] = 0;
    for (int i = n - 1; i >= 0; --i)
        for (int bit = 0; bit < 2; bit++)
        {
            int sbit = s[i] - '0';
            if (sbit == bit)
            {
                dpEq[i] = max(dpEq[i], dpEq[i + 1] + bit * a[i]);
                dpSmall[i] = max(dpSmall[i], dpSmall[i + 1] + bit * a[i]);
            }
            if (sbit > bit)
                dpSmall[i] = max(dpSmall[i], max(dpEq[i + 1], dpSmall[i + 1]) + bit * a[i]);
            if (sbit < bit)
                dpSmall[i] = max(dpSmall[i], dpSmall[i + 1] + bit * a[i]);
        }
    cout << max(dpSmall[0], dpEq[0]);

    return 0;
}