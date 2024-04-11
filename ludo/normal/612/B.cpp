#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN (200 * 1000)

int n, a[MAXN], idx[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i] - 1] = i;
    }

    long long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += abs(idx[i] - idx[i - 1]);
    }
    cout << sum << endl;
    return 0;
}