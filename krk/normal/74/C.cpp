#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    do {
        if (n > m) swap(n, m);
        if (n == 1) break;
        m = m - n + 1;
    } while (true);
    cout << m << endl;
    return 0;
}