#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m, k;
int b[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    vector <int> seq;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (i) seq.push_back(b[i] - b[i - 1] - 1);
    }
    sort(seq.rbegin(), seq.rend());
    int res = b[n - 1] - b[0] + 1;
    for (int i = 0; i < k - 1; i++)
        res -= seq[i];
    printf("%d\n", res);
    return 0;
}