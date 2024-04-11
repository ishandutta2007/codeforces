#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    cout << 1 + n + n + n - 1 + min(n - k, k - 1) << endl;
    return 0;
}