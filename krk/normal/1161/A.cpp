#include <bits/stdc++.h>
using namespace std;

const int Maxm = 100005;

int n, k;
vector <int> seq[Maxm];
int res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a; scanf("%d", &a);
        seq[a].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (seq[i].empty()) res++;
        if (i > 1 && (seq[i].empty() || seq[i - 1].empty() || seq[i - 1].back() < seq[i][0]))
            res++;
        if (i < n && (seq[i].empty() || seq[i + 1].empty() || seq[i + 1].back() < seq[i][0]))
            res++;
    }
    printf("%d\n", res);
    return 0;
}