#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
int L[Maxn], R[Maxn];
int myl[Maxn], myr[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    vector <ii> seq;
    for (int i = 0; i < n; i++)
        scanf("%d", &L[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &R[i]);
        seq.push_back(ii(L[i] + R[i], i));
    }
    sort(seq.rbegin(), seq.rend());
    int cur = 1;
    for (int i = 0, j; i < seq.size(); i = j) {
        j = i;
        while (j < seq.size() && seq[i].first == seq[j].first) {
            res[seq[j].second] = cur;
            j++;
        }
        cur++;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (res[i] > res[j]) myl[j]++;
            else if (res[i] < res[j]) myr[i]++;
    for (int i = 0; i < n; i++)
        if (L[i] != myl[i] || R[i] != myr[i]) { printf("NO\n"); return 0; }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}