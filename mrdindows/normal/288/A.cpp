#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
int a[200000];
int main()
{
    cin >> n >> k;
    string s = "", s1 ="";
    if (k > n)
    {
        cout << -1;
        return 0;
    }
    if (n == 1)
    {
        cout << 'a';
        return 0;
    }
    if (k == 1)
    {
        cout << -1;
        return 0;
    }
    n = n - k + 1;
    for (int i = k - 1; i > 1; --i)
        s = (char)('a' + i) + s;
    for (int i = 0; i <= n; ++i)
        s1 += (char)('a' + (i % 2));
    s = s1 + s;
    cout << s;


}