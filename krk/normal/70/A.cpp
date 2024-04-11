#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 0) cout << "1\n";
    else {
         int res = 1;
         for (int i = 1; i < n; i++) res = 3 * res % 1000003;
         cout << res << endl;
    }
    return 0;
}