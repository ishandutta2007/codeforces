#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int freq[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    vector <int> res1, res2;
    for (int i = 0; i < Maxn; i++)
        if (freq[i] > 0) { res1.push_back(i); freq[i]--; }
    for (int i = 0; i < Maxn; i++)
        if (freq[i] > 0) { res2.push_back(i); freq[i]--; }
    if (int(res1.size()) + int(res2.size()) < n) { printf("NO\n"); return 0; }
    printf("YES\n");
    printf("%d\n", int(res1.size()));
    for (int i = 0; i < res1.size(); i++)
        printf("%d%c", res1[i], i + 1 < res1.size()? ' ': '\n');
    printf("%d\n", int(res2.size()));
    for (int i = int(res2.size()) - 1; i >= 0; i--)
        printf("%d%c", res2[i], i - 1 >= 0? ' ': '\n');
    return 0;
}