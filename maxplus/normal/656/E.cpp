#include <algorithm>
#include <iostream>

using namespace std;

int n, a[11][11], ans;

int read_it(int i, int j)
{
    i += j / n, j %= n;
    return i != n? cin >> a[i][j], read_it(i, j + 1): 0;
}

int do_it(int k, int i, int j)
{
    i += j / n, j %= n;
    k += i / n, i %= n;
    return k != n? a[i][j] = min(a[i][j], a[i][k] + a[k][j]), do_it(k, i, j + 1): 0;
}

int calc_it(int i)
{
    return i != n? ans = max(ans, *max_element(a[i], a[i] + n)), calc_it(i + 1): 0;
}

int main()
{
    cin >> n;
    read_it(0, 0);
    do_it(0, 0, 0);
    calc_it(0);
    cout << ans;
    return 0;
}