#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        printf("%c", i % 2 + '0');
    printf("\n");
    return 0;
}