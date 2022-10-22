#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400015;
const int Maxd = 3;

int T;
int n;
char str[Maxn];
int N;
int BIT[Maxd][Maxn];

void Add(int BIT[], int x)
{
    for (int i = x + n + 1; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(int BIT[], int x)
{
    int res = 0;
    for (int i = x + n + 1; i <= N; i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        N = 2 * n;
        for (int i = 0; i < Maxd; i++)
            fill(BIT[i], BIT[i] + N + 1, 0);
        ll res = 0;
        int st = 0;
        Add(BIT[0], 0);
        for (int i = 0; i < n; i++) {
            st += str[i] == '+'? 1: -1;
            int wh = st % Maxd;
            if (wh < 0) wh += Maxd;
            res += Get(BIT[wh], st);
            Add(BIT[wh], st);
        }
        printf("%I64d\n", res);
    }
    return 0;
}