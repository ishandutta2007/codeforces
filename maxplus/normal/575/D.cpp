#include <iostream>

using namespace std;

int main()
{
    cout << "1999\n";
    for (int i = 1; i < 1001; ++i)
        cout << i << " 1 " << i << " 2\n";
    for (int i = 2; i < 1001; ++i)
        cout << i << " 1 " << i << " 2\n";
    return 0;
}