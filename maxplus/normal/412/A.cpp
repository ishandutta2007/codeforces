#include <iostream>
#include <cstdlib>
#include <cstdio>

//#include <algorithm>
//#include <cstring>
//#include <string>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <cmath>


using namespace std;

int main()
{
    int n, k;
    char s[101];
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    if (k > n / 2)
    {
        for (int i = k; i < n; ++i)
            cout << "RIGHT\n";

        cout << "PRINT " << s[n - 1];
        for (int i = n - 2; i >= 0; --i)
            cout << "\nLEFT\nPRINT " << s[i];
    }
    else
    {
        for (int i = k; i > 1; --i)
            cout << "LEFT\n";

        cout << "PRINT " << s[0];
        for (int i = 1; i < n; ++i)
            cout << "\nRIGHT\nPRINT " << s[i];
    }
    return 0;
}