#include <iostream>

using namespace std;

int a[10];

int main()
{
    int n;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (c == '9')
            ++a[7], ++++a[3], ++a[2];
        if (c == '8')
            ++a[7], ++++++a[2];
        if (c == '7')
            ++a[7];
        if (c == '6')
            ++a[5], ++a[3];
        if (c == '5')
            ++a[5];
        if (c == '4')
            ++a[3], ++++a[2];
        if (c == '3')
            ++a[3];
        if (c == '2')
            ++a[2];
    }
    for (int i = 8; --i;)
        while (a[i]--)
            cout << i;
    return 0;
}