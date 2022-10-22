#include <iostream>
using namespace std;

int n;

int main()
{
    int i;
    cin >> n;
    if (n % 2 == 1) {
         cout << 1;
         for (i = 2; i <= n; i++)
            if (i % 2 == 0) cout << " " << i+1;
            else cout << " " << i-1;
         cout << endl;
    } else {
           for (i = 1; i <= n; i++) {
               if (i > 1) cout << " ";
               if (i % 2 == 0) cout << i-1;
               else cout << i+1;
           }
           cout << endl;
    }
    return 0;
}