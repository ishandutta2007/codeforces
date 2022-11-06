#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int n, a[1000000], cur;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i-1] && cur != 0)
        {
            cout << "NO";
            return 0;
        }
        if (a[i] == a[i-1])
            if (cur == 0)
                cur++;
            else
                if (cur == 2)
                {
                    cout << "NO";
                    return 0;
                }
        if (a[i] < a[i-1])
                cur = 2;
    }
    cout << "YES";

    return 0;
}