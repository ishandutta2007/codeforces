#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    int a[n][n];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    cin >> a[i][j];
    
    int s = 0;
    
    for(int i = 0; i < n; ++i)
            s += a[i][i];
    for(int i = 0; i < n; ++i)
            s += a[n - i - 1][i];
    for(int i = 0; i < n; ++i)
            s += a[n / 2][i] + a[i][n / 2];
    
    cout << s - 3 * a[n / 2][n / 2];
    
    cin >> n;
    
    return 0;
}