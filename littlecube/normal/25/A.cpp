#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n;
    stack<int> a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if (k % 2)
            a.push(i);
        else
            b.push(i);
    }
    if (a.size() == 1)
        cout << a.top();
    else
        cout << b.top();
}