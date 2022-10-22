#include <iostream>
using namespace std;

const int Maxn = 1001;

int n, k, b[Maxn], a[Maxn];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int take;
        for (int j = 1; j <= n; j++) if (b[j] == 0) { b[j]--; take = j; break; }
        for (int j = 1; j <= n; j++) if (take >= j + k) b[j]--;
        a[i] = take;
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}