#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2)
        {
            result++;
        }
    }
    cout << result << '\n';
}