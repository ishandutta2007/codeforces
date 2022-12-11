#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int aa[4];

int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        aa[a]++;
    }
    cout << n - max(aa[1], max(aa[2], aa[3]));
};