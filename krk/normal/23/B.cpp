#include <iostream>
#include <cstdio>
using namespace std;

int t;
int n;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
          cin >> n;
          if (n <= 2) cout << "0\n";
          else cout << n - 2 << endl;
    }
    return 0;
}