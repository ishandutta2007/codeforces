#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0;
    while (i < n && a[i] == 1) i++;
    if (i == n) {
          for (int i = 0; i < n - 1; i++)
              cout << "1 ";
          cout << "2\n";
    } else {
           sort(a, a + n);
           cout << "1";
           for (int i = 0; i < n - 1; i++)
               cout << " " << a[i];
           cout << endl;
    }
    return 0;
}