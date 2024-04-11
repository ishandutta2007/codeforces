#include <iostream>
#include <algorithm>
using namespace std;

int a, b, n;

bool isPower(int a, int x)
{
    if (a == 0) return x == 0;
    int res = 1, i;
    for (i = 0; i < n; i++)
       if (res <= x / a) res *= a;
       else break;
    return i == n && res == x;
}

int main()
{
    cin >> a >> b >> n;
    if (a == 0) if (b == 0) cout << "0\n";
                else cout << "No solution\n";
    else if (b % a) cout << "No solution\n";
    else {
         int to = abs(b / a), i;
         for (i = 0; i <= to; i++)
            if (isPower(i, to)) break;
         if (i > to) cout << "No solution\n";
         else if (b / a < 0) cout << -i << endl;
              else cout << i << endl;
    }
    return 0;
}