#include <iostream>
using namespace std;

const int Maxn = 1000;

int n, a[Maxn];

int main()
{
    int mn = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && a[l] <= a[l + 1]) l--;
        while (r < n && a[r - 1] >= a[r]) r++;
        if (r - l - 1 > mn) mn = r - l - 1;
    }
    cout << mn << endl;
    return 0;
}