#include <iostream>
#include <algorithm>
using namespace std;

int x;

int main()
{
    cin >> x;
    x = abs(x);
    int now = 0, step = 1;
    while (now < x || now % 2 != x % 2)
       now += step++;
    cout << step - 1 << endl;
    return 0;
}