#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
int X[Maxn], Y[Maxn];
vector <ii> seq;

int main()
{
    scanf("%d", &n);
    if (n % 2) { printf("NO\n"); return 0; }
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        seq.push_back(ii(X[ni] - X[i], Y[ni] - Y[i]));
    }
    for (int i = 0; i < n / 2; i++)
        if (seq[i].first != -seq[n / 2 + i].first ||
            seq[i].second != -seq[n / 2 + i].second) {
                printf("NO\n"); return 0;
            }
    printf("YES\n");
    return 0;
}