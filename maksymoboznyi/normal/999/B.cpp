#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;
const int N = 4e5+5;
const long long inf = 2e18;

string s, t;
int n;

signed main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
        {
            s = "";
            for (int j = i-1; j >= 0; j--)
                s += t[j];
            for (int j = i; j < n; j++)
                s += t[j];
            t = s;
        }
    cout << t;
    return 0;
}