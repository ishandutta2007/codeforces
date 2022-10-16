#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 3)
        cout << "YES\n";
    if (n == 4)
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24";
    else if (n == 5)
        cout << "4 + 3 = 7\n7 - 2 = 5\n5 * 5 = 25\n25 - 1 = 24";
    else if (n >= 6)
    {
        printf("%d - %d = 1\n1 - 1 = 0\n", n, n - 1);
        n = n - 2;
        while (n > 4)   printf("0 * %d = 0\n", n--);
        cout << "0 + 2 = 2\n2 * 3 = 6\n6 * 4 = 24";
    }
    else
        cout << "NO";
    return 0;
}