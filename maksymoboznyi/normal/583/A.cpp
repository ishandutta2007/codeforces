#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
bool u1[N], u2[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n*n; i++) {
        int a, b;
        cin >> a >> b;
        if (!u1[a] && !u2[b])
            cout << i << " ", u1[a] = 1, u2[b] = 1;
    }
    return 0;
}