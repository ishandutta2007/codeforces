#include <iostream>
using namespace std;

int n;

int main()
{
    int i, no = 1, thr = 1;
    cin >> n;
    for (i = 1; i < n; i++) {
        no += thr;
        if (no > n) no %= n;
        thr++;
        if (i > 1) cout << " ";
        cout << no;
    }
    cout << endl;
    return 0;
}