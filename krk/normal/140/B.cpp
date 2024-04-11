#include <iostream>
#include <cstdio>
using namespace std;

const int Maxn = 305;

int n, a[Maxn][Maxn];

bool Check(int x, int h)
{
     for (int j = 1; j <= n; j++)
         if (a[0][j] == x) return true;
         else if (a[0][j] < x && a[0][j] != h) return false;
     return true;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int j = 1; j <= n; j++) cin >> a[0][j];
    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (a[i][j] == i || !Check(a[i][j], i)) j++;
        cout << a[i][j];
        if (i < n) cout << " ";
    }
    cout << endl;
    return 0;
}