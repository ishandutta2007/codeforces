#include <iostream>

using namespace std;

const long long MAXD = ((long long)1 << 60);

int main()
{
    long long n, l, r, cd;
    cin >> n;
    while (n-- > 0)
    {
        cin >> l >> r;
        cd = MAXD;
        while ((r + 1) / cd == l / cd)
            cd >>= 1;
        cout << ((r + 1) / cd) * cd - 1 << '\n';
    }
    return 0;
}