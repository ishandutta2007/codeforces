#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    while (n != 1) {
          cout << n << " ";
          int i;
          for (i = 2; i * i <= n; i++)
             if (n % i == 0) break;
          if (i * i > n) n = 1;
          else n /= i;
    } 
    cout << "1\n";
    return 0;
}