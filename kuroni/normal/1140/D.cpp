#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i < n; i++)
        ans += i * (i + 1);
    cout << ans;
}