#include <iostream>

using namespace std;

bool A, a, s, l;

int main()
{
    char c;
    for (int i = 0; cin >> c > 0 && c != '#'; ++i)
    {
        if (c >= '0' && c <= '9')
            s = 1;
        else if (c >= 'a' && c <= 'z')
            a = 1;
        else if (c >= 'A' && c <= 'Z')
            A = 1;
        if (i == 4)
            l = 1;
    }
    if (s && a && A && l)
        cout << "Correct";
    else
        cout << "Too weak";
    return 0;
}