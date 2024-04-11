#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
          cin >> n;
          if (n % 2) cout << "0\n";
          else cout << "1\n";
    }
    return 0;
}