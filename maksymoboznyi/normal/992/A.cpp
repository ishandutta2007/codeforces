#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 1e5+5;
const long long inf = 2e18;

int n, a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int kol = 0, sum = 0;
    a[0] = -999999999;
    for (int i = 1; i <= n; i++)
        if (a[i] != 0 && a[i] != a[i-1])
            kol++;

    cout << kol;
    return 0;
}