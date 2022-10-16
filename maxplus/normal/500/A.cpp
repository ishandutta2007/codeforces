#include <iostream>

using namespace std;

int main()
{
    static int n, t, a, sum = 1, m[100000];
    cin >> n >> t;
    for (int i = 1; i < n; ++i)
    {
        cin >> a;
        if (i == sum)
            m[sum += a] = 1;
    }
    cout << (m[t]? "YES":"NO");
    return 0;
}