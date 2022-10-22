#include <iostream>
using namespace std;

const int Maxn = 100000;

int n, t[Maxn], alice[Maxn], bob[Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    alice[0] = 0;
    for (int i = 1; i < n; i++)
       alice[i] = alice[i-1] + t[i-1];
    bob[n-1] = 0;
    for (int j = n-2; j >= 0; j--)
       bob[j] = bob[j+1] + t[j+1];
    int a = 0;
    while (a < n && alice[a] <= bob[a]) a++;
    cout << a << " " << n-a << endl;
    return 0;
}