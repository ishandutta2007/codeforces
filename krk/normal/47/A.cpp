#include <iostream>
using namespace std;

int n;

bool Triangular(int n)
{
     int i, sum = 0;
     for (i = 0; ; i++) {
         sum += i;
         if (sum > n) return false;
         else if (sum == n) return true;
     }
}

int main()
{
    cin >> n;
    if (Triangular(n)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}