#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> seq;

void Apply(int ind)
{
    int xr = (a[ind] ^ a[ind + 1] ^ a[ind + 2]);
    a[ind] = a[ind + 1] = a[ind + 2] = xr;
    seq.push_back(ind);
}

bool Solve(int n)
{
    if (n == 1) return a[1] == 0;
    else if (n == 2) return a[1] == 0 && a[2] == 0;
    else if (n == 3) {
        int cnt = 0;
        for (int i = 1; i <= 3; i++)
            cnt += a[i];
        if (cnt % 2) return false;
        if (cnt > 0) seq.push_back(1);
        return true;
    } else if (a[n - 1] == 0 && a[n] == 0) return Solve(n - 1);
    else if (a[n - 3] == 0 && a[n - 2] == 0 && a[n - 1] == 1 && a[n] == 0) {
        Apply(n - 3);
        Apply(n - 2);
        return Solve(n - 1);
    } else if (a[n - 3] == 1 && a[n - 2] == 0 && a[n - 1] == 1 && a[n] == 0) {
        Apply(n - 3);
        return Solve(n - 1);
    } else if (a[n - 2] == 1 && a[n - 1] == 1 && a[n] == 0) {
        Apply(n - 2);
        return Solve(n - 1);
    } else if (a[n - 2] == 0 && a[n - 1] == 0 && a[n] == 1) {
        Apply(n - 2);
        bool ret = Solve(n - 2);
        if (!ret) return false;
        Apply(n - 2);
        return true;
    } else if (a[n - 2] == 1 && a[n - 1] == 0 && a[n] == 1) {
        Apply(n - 2);
        return Solve(n - 1);
    } else if (a[n - 2] == 0 && a[n - 1] == 1 && a[n] == 1) {
        Apply(n - 2);
        return Solve(n - 1);
    } else if (a[n - 2] == 1 && a[n - 1] == 1 && a[n] == 1) {
        bool ret = Solve(n - 2);
        if (!ret) return false;
        Apply(n - 2);
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        seq.clear();
        if (Solve(n)) {
            printf("YES\n");
            printf("%d\n", int(seq.size()));
            for (int i = 0; i < seq.size(); i++)
                printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
        } else printf("NO\n");
    }
    return 0;
}