#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8;
const int maxn = 1e2 + 1;
int main()
{
    int k , r;
    cin >> k >> r;
    for(int i = 1; i < 100000; i++)
    {
        if(i * k % 10 == r || i * k % 10 == 0)
        {
            cout << i;
            return 0;
        }
    }
}