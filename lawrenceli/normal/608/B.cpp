#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 200100;

int n, m;
char a[maxn], b[maxn];
int p[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> a >> b;
    n = strlen(a), m = strlen(b);
    for (int i = 0; i < m; i++)
        p[i + 1] = p[i] + b[i] - '0';

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') ans += p[m-n+i+1] - p[i];
        else ans += (m-n+1) - (p[m-n+i+1] - p[i]);
    }

    cout << ans << '\n';
}