#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

pair<int, int> a[100];
int sol[100], sol_n = 0;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(&a[0], &a[n]);

    for (int i = 0; i < n && k >= a[i].first; i++) {
        sol[sol_n++] = a[i].second;
        k -= a[i].first;
        // cerr << "adding " << a[i].first << ", " << a[i].second << " left=" << k << endl;
    }

    sort(&sol[0], &sol[sol_n]);

    cout << sol_n << endl;
    for (int i = 0; i < sol_n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << (sol[i] + 1);
    }
    if (n > 0) {
        cout << endl;
    }

    return 0;
}