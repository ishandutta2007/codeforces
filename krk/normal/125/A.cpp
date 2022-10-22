#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int in = n / 3;
    if (n % 3 > 1) in++;
    int f = in / 12;
    cout << f << " " << in % 12 << endl;
    return 0;
}