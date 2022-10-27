#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;
    int n = sqrt(x);
    if(x == n * n)
    {
        cout << 2 * n;
    }
    else if(x <= n * n + n)
    {
        cout << 2 * n + 1;
    }
    else
    {
        cout << 2 * n + 2;
    }
    return 0;
}