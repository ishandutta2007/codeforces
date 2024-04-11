#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        res += a[i];
    }
    cout << res << endl;
    return 0;
}