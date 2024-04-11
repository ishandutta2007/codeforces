#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 55;

int main()
{
    int n, m, i[maxn], k, sum = 0, r = 0, mi, ma, kol = 2e9;
    scanf ( "%d%d", &n, &m );
    for ( k = 0; k < m; k++ )
        scanf ( "%d", &i[k] );
    sort ( i, i + m );
    for ( k = 0; k <= m - n; k++ ){
        mi = 2e9;
        ma = -2e9;
        for ( r = k; r < n + k; r++ ){
            ma = max ( ma, i[r] );
            mi = min ( mi, i[r] );
        }
        kol = min ( kol, ma - mi );
    }
    printf ( "%d", kol );
    return 0;
}