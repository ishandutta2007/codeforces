#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (1 << n) - 1 << endl;
    }
    return 0;
}