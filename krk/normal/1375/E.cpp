#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
int a[Maxn];
ii seq[Maxn];
vector <ii> res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq[i] = ii(a[i], i);
    }
    sort(seq, seq + n);
    for (int i = 0; i < n; i++) {
        int ind = seq[i].second;
        for (int j = n - 1; j > ind; j--)
            if (a[ind] > a[j]) res.push_back(ii(ind + 1, j + 1));
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}