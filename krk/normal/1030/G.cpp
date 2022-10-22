#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 2000005;
const int mod = 1000000007;

int mx[Maxm];
int n;
int has[Maxm];
vector <int> cnt[Maxm];
int seq[Maxm], slen;
int res = 1;
bool add;

void Add(int x)
{
    seq[slen++] = x;
    while (x > 1) {
        int cur = mx[x], c = 0;
        while (mx[x] == cur) {
            x /= cur; c++;
        }
        cnt[cur].push_back(c);
    }
}

bool Check(int x)
{
    while (x > 1) {
        int cur = mx[x], c = 0;
        while (mx[x] == cur) {
            x /= cur; c++;
        }
        if (cnt[cur].size() == 1 || cnt[cur].back() == c && c != cnt[cur][int(cnt[cur].size()) - 2])
            return false;
    }
    return true;
}

int main()
{
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        has[a]++;
    }
    for (int i = Maxm - 1; i > 0; i--)
        for (int j = 0; j < has[i]; j++)
            if (cnt[i].empty()) Add(i);
            else Add(i - 1);
    for (int i = 1; i < Maxm; i++) if (!cnt[i].empty()) {
        sort(cnt[i].begin(), cnt[i].end());
        for (int j = 0; j < cnt[i].back(); j++)
            res = ll(res) * i % mod;
    }
    for (int i = 0; i < slen && !add; i++)
        add = Check(seq[i]);
    if (add) res = (res + 1) % mod;
    printf("%d\n", res);
    return 0;
}