#include <bits/stdc++.h>

using namespace std;
long long n, a[100];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a + n+1);
    cout << a[n/2+1];//<< ' ' << a[1] << ' ' << a[2] << ' ' << a[3];
    return 0;
}