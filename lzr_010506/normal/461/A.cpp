#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, a[N];
int main () 
{
    scanf("%d", &n);

    long long sum = 0;
    for (int i = 1; i <= n; i ++) 
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sort(a + 1, a + 1 + n);

    long long ans = sum;
    for (int i = 1; i < n; i ++) 
    {
        ans += sum;
        sum -= a[i];
    }
    cout << ans;
    return 0;
}