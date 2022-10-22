#include <iostream>
using namespace std;

int main()
{
    long long n, m, x, left = 0;
    cin >> n >> m >> x;
    n -= x-1; n -= x-1;
    m -= x-1; m -= x-1;
    if (n > 0 && m > 0) {
          if (m % 2 == 1) left += m/2+1;
          else left += m/2;
          left += (n-1)/2;
          if (m > 1) if (m % 2 == 1) left += (n-1)/2;
                     else left += n/2;
          if (m > 1 && n > 1) if (m % 2 == 1) if (n % 2 == 1) left += m/2-1;
                                              else left += m/2; 
                              else left += m/2 - 1;
    }
    cout << left << endl;
    return 0;
}