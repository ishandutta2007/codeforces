#include <iostream>
using namespace std;

typedef unsigned long long ull;

int n;
ull sum;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ull a; cin >> a;
        sum += ull(i) * (a - 1LL) + 1LL;
    }
    cout << sum << endl;
    return 0;
}