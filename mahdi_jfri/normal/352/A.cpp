#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
    int n, a = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k == 5){a++;}
    }
    if (a < 9 && a != n ){cout << 0; return 0;}
    if (a == n ){cout << -1; return 0;}
    int g = (int)(a / 9) * 9;
    for (int i = 0; i < g; i++){cout << '5';}
    for (int i = 0; i < n - a; i++){cout << '0';}
    return 0;

}