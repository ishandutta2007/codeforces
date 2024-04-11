#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> rem[Maxn];
int BIT[Maxn];
long long res;

void Add(int ind, int val)
{
    for (int i = ind; i <= n; i += i & -i)
        BIT[i] += val;
}

int Get(int ind)
{
    int res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        res += Get(min(a[i], i - 1));
        if (a[i] > i) {
            Add(i, 1);
            if (a[i] < Maxn)
                rem[a[i]].push_back(i);
        }
        for (int j = 0; j < rem[i].size(); j++)
            Add(rem[i][j], -1);
    }
    cout << res << endl;
    return 0;
}