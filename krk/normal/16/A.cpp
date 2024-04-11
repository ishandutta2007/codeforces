#include <iostream>
using namespace std;

const int Maxn = 100;

int n, m;
char B[Maxn][Maxn];

int main()
{
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++)
       for (j = 0; j < m; j++) cin >> B[i][j];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m-1; j++)
           if (B[i][j] != B[i][j+1]) break;
        if (j < m-1) break;
    }
    if (i < n) cout << "NO\n";
    else {
         for (i = 0; i < n-1; i++)
            if (B[i][0] == B[i+1][0]) break;
         if (i < n-1) cout << "NO\n";
         else cout << "YES\n";
    }
    return 0;
}