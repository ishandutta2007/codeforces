#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

const int N = 1E4, M = 50;

int m, n, u, v;
bitset<N> a[M];

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> u;
        while (u--)
        {
            cin >> v;
            a[i].set(v - 1);
        }
        for (int j = 0; j < i - 1; j++)
            if (!(a[i] & a[j]).any())
                return cout << "impossible", 0;
    }
    cout << "possible";
}