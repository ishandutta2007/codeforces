#include <iostream>
using namespace std;

const int Maxn = 100005;

int a, b, m, r;
int was[Maxn];

int main()
{
    cin >> a >> b >> m >> r;
    was[r] = 1;
    for (int i = 2; ; i++) {
        r = (a * r + b) % m;
        if (was[r]) { cout << i - was[r] << endl; break; }
        was[r] = i;
    }
    return 0;
}