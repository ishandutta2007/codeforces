#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    int k, n, a[101];
    cin >> k >> n;
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    sort(a, a + k);
    cout << a[k - n];
    return 0;
}