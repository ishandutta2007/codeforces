#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll res;

int main()
{
    cin >> n;
    while (n >= 3) {
        res += n * (n - 1);
        n--;
    }
    cout << res << endl;
    return 0;
}