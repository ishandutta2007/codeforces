#include <iostream>
#include <cstdio>
using namespace std;

int n, ans = 0;
string a, b;

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != b[i])
        {
            ++ans;
            if (a[i] != a[i + 1] && b[i] != b[i + 1])
                swap(a[i], a[i + 1]);
        }
    ans += (a[n - 1] != b[n - 1]);
    cout << ans;
}