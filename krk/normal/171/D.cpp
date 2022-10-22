#include <iostream>
using namespace std;

int p[5] = {2, 3, 1, 2, 1};

int a;

int main()
{
    cin >> a;
    cout << p[a - 1] << endl;
    return 0;
}