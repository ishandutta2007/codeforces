#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n % 3 == 0)
        cout << "1 1 " << n - 2;
    else
        cout << "1 2 " << n - 3;
}