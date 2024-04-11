#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n, m, t, mi, ma, smi = 1000000000, sma = -1;
    cin >> n >> m >> mi >> ma;
    for (int i = 0; i < m; ++i)
    {
        cin >> t;
        smi = min(smi, t);
        sma = max(sma, t);
    }
    if (smi < mi || sma > ma)
        cout << "Incorrect";
    else if (smi == mi || sma == ma)
        cout << "Correct";
    else if (m <= n - 2)
        cout << "Correct";
    else
        cout << "Incorrect";
    return 0;
}