#include <iostream>

using namespace std;

#define DIGS 7

int pow10[DIGS + 1], d[DIGS], n, ret[10] = {};

int main()
{
    pow10[0] = 1;
    for (int i = 1; i <= DIGS; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }

    int num;
    cin >> num;

    while (num > 0) {
        d[n++] = num % 10;
        num /= 10;
    }

    int maxd = 0;
    for (int i = 0; i < n; i++) {
        maxd = max(maxd, d[i]);
    }

    cout << maxd << endl;

    for (int i = 0; i < maxd; i++) {
        for (int j = 0; j < n; j++) {
            if (d[j] > 0) {
                d[j]--;
                ret[i] += pow10[j];
            }
        }
    }

    for (int i = 0; i < maxd; i++) {
        if (i != 0) cout << " ";
        cout << ret[i];
    }
    cout << endl;

    return 0;
}