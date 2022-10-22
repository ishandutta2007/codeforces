#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull a, b;

int main()
{
    cin >> a >> b;
    if (a < b || a % 2 != b % 2) cout << "-1\n";
    else {
         ull lft = (a - b) >> 1;
         if (lft & b) cout << "-1\n";
         else {
              ull y = b + lft;
              ull x = a - y;
              cout << x << " " << y << endl;
         }
    }
    return 0;
}