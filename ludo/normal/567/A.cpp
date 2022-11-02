#include <iostream>

using namespace std;

#define MAXN 100000

int n, x[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        int minx = 2147483647;
        if (i > 0) minx = min(minx, x[i] - x[i - 1]);
        if (i + 1 < n) minx = min(minx, x[i + 1] - x[i]);

        int maxx = -2147483647;
        if (i > 0) maxx = max(maxx, x[i] - x[0]);
        if (i + 1 < n) maxx = max(maxx, x[n - 1] - x[i]);

        cout << minx << " " << maxx << endl;
    }
    return 0;
}