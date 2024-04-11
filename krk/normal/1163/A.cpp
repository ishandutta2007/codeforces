#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    if (m == 0) printf("1\n");
    else printf("%d\n", min(m, n - m));
    return 0;
}