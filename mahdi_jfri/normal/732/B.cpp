#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8;
const int maxn = 5e3 + 1;
int a[maxn];
int n , k;
int res;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        if(a[i] + a[i - 1] < k)
        {
            res += k - (a[i] + a[i - 1]);
            a[i] += k - (a[i] + a[i - 1]);
        }
    }
    cout << res << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}