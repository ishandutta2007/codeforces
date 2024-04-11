#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
int a[Maxn], b[Maxn];
ll cur;
vector <int> seq;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        cur += a[i];
        seq.push_back(a[i] - b[i]);
    }
    sort(seq.rbegin(), seq.rend());
    int pnt = 0;
    while (cur > m)
        if (pnt >= seq.size()) { printf("-1\n"); return 0; }
        else cur -= seq[pnt++];
    printf("%d\n", pnt);
    return 0;
}