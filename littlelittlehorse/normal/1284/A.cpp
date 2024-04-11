#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string a[21], c[21];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) 
        cin >> c[i];
    int Q;
    scanf("%d", &Q);
    for (; Q--;) {
        int x;
        scanf("%d", &x);
        --x;
        cout << a[x % n] << c[x % m] << endl;
    }
}