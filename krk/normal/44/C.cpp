#include <iostream>
using namespace std;

const int Maxn = 101;

int n, m, tims[Maxn];

int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        for (int j = a; j <= b; j++) tims[j]++;
    }
    int i;
    for (i = 1; i <= n; i++)
       if (tims[i] != 1) { cout << i << " " << tims[i] << endl;  break; }
    if (i > n) cout << "OK\n";
    return 0;
}