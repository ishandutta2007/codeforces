#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, result[5];
    cin >> n;
    result[4] = n / 100;
    n -= result[4] * 100;
    result[3] = n / 20;
    n -= result[3] * 20;
    result[2] = n / 10;
    n -= result[2] * 10;
    result[1] = n / 5;
    n -= result[1] * 5;
    cout << result[4] + result[3] + result[2] + result[1] + n;
}