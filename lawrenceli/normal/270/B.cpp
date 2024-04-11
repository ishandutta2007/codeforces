#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int n, minn;
int a[MAXN];

int main() {
    //freopen("270B.in", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    minn=a[n];
    for (int i=n-1; i>=1; i--) {
        if (a[i]>minn) {
            cout << i << endl;
            return 0;
        }
        minn=min(minn, a[i]);
    }
    cout << 0 << endl;
}