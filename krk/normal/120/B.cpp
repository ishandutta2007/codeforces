#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int Maxn = 1005;

int n, k;
int a[Maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (!a[k]) (k < n)? k++: k = 1;
    cout << k << endl;
    return 0;
}