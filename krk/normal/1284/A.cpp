#include <bits/stdc++.h>
using namespace std;

const int Maxn = 25;

int n, m;
string A[Maxn], B[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int q; scanf("%d", &q);
    while (q--) {
        int y; scanf("%d", &y); y--;
        printf("%s%s\n", A[y % n].c_str(), B[y % m].c_str());
    }
    return 0;
}