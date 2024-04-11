#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int v = (n / m) * b;
    if (n % m != 0)
        v += min((n % m) * a, b);

    if (n*a < v)
        cout << n * a << endl;
    else
    {
        cout << v << endl;
    }
}