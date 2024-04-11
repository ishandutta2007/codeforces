#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;
const int N = 1000;
ll a[N], n, kol = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            kol++;
    }
    if (a[1] % 2 == 0 || a[n] % 2 == 0)
        cout << "No";else
    if (n % 2 == 1)
            cout << "Yes";
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
        if ((i-1)%2 == 0 && (j - i - 1)%2 == 0 && (n-j-1)%2 == 0 && a[i] % 2 != 0 && a[i+1]%2!=0 && a[j] % 2 != 0 && a[j+1] % 2 != 0)
        {
            cout << "Yes";
            return 0;
        }
        cout << "No";

    }
    return 0;
}