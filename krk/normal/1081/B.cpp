#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
vector <int> freq[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[n - a].push_back(i);
    }
    int cur = 0;
    for (int i = 1; i <= n; i++)
        if (freq[i].size() % i == 0) {
            for (int j = 0; j < freq[i].size() / i; j++) {
                cur++;
                for (int k = 0; k < i; k++)
                    res[freq[i][j * i + k]] = cur;
            }
        } else { printf("Impossible\n"); return 0; }
    printf("Possible\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}