#include <iostream>
using namespace std;

int n, m;

int main()
{
    int i, j;
    cin >> n >> m;
    if (n == 1 && m == 2) {
          cout << 0 << endl;
          cout << 1 << " " << 1 << endl;
          cout << 1 << " " << 2 << endl;
          cout << 1 << " " << 1 << endl;
    } else if (n == 2 && m == 1) {
           cout << 0 << endl;
           cout << 1 << " " << 1 << endl;
           cout << 2 << " " << 1 << endl;
           cout << 1 << " " << 1 << endl;
    } else if (n == 1) {
          cout << 1 << endl;
          cout << 1 << " " << m << " " << 1 << " " << 1 << endl;
          for (j = 1; j <= m; j++)
             cout << 1 << " " << j << endl;
          cout << 1 << " " << 1 << endl;
    } else if (m == 1) {
          cout << 1 << endl;
          cout << n << " " << 1 << " " << 1 << " " << 1 << endl;
          for (i = 1; i <= n; i++)
             cout << i << " " << 1 << endl;
          cout << 1 << " " << 1 << endl;
    } else if (n % 2 == 0) {
           cout << 0 << endl;
           cout << 1 << " " << 1 << endl;
           for (i = 1; i <= n; i++)
              if (i % 2)
                 for (j = 2; j <= m; j++) cout << i << " " << j << endl;
              else for (j = m; j >= 2; j--) cout << i << " " << j << endl;
           for (i = n; i >= 1; i--)
              cout << i << " " << 1 << endl;
    } else if (m % 2 == 0) {
           cout << 0 << endl;
           cout << 1 << " " << 1 << endl;
           for (j = 2; j <= m; j++)
              if (j % 2)
                 for (i = n-1; i >= 1; i--)
                    cout << i << " " << j << endl;
              else for (i = 1; i <= n-1; i++)
                 cout << i << " " << j << endl;
           for (j = m; j >= 2; j--)
              cout << n << " " << j << endl;
           for (i = n; i >= 1; i--)
              cout << i << " " << 1 << endl;
    } else {
           cout << 1 << endl;
           cout << n << " " << m << " " << 1 << " " << 1 << endl;
           for (i = 1; i <= n; i++)
              if (i % 2)
                 for (j = 1; j <= m; j++)
                    cout << i << " " << j << endl;
              else for (j = m; j >= 1; j--)
                 cout << i << " " << j << endl;
           cout << 1 << " " << 1 << endl; 
    }
    return 0;
}