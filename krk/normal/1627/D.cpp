#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
int cnt[Maxn];
ll my[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = Maxn - 1; i > 0; i--) {
        int got = 0;
        for (int j = i; j < Maxn; j += i)
            got += cnt[j];
        my[i] = ll(got) * got;
        for (int j = i + i; j < Maxn; j += i)
            my[i] -= my[j];
        if (my[i] > 0 && cnt[i] == 0) {
            cnt[i] = 1;
            my[i] += ll(got + 1) * (got + 1) - ll(got) * got;
        }
        res += cnt[i];
    }
    cout << res - n << endl;
    return 0;
}