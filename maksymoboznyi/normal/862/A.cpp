#include <iostream>

using namespace std;

int n, x;
int a[101], kol[102];

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i], kol[a[i]]++;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < x; i++)
        if (kol[i] == 0)
            ans2++;

    cout << ans2 + kol[x];
    return 0;
}