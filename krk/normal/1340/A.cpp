#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int p[Maxn];
int inp[Maxn];

bool Check()
{
    map <int, int> M;
    map <int, int> cnt;
    int mx = 1;
    for (int i = 1; i <= n; i++)
        M[i] = 1;
    cnt[1] += n;
    for (int i = 1; i <= n; i++) {
        int ind = inp[i];
        map <int, int>::iterator it = M.find(ind);
        if (it->second != cnt.rbegin()->first) return false;
        int add = it->second;
        if (--cnt[add] == 0) cnt.erase(add);
        M.erase(it++);
        if (it != M.end()) {
            if (--cnt[it->second] == 0) cnt.erase(it->second);
            it->second += add;
            cnt[it->second]++;
            mx = max(mx, it->second);
        }
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            inp[p[i]] = i;
        }
        printf("%s\n", Check()? "Yes": "No");
    }
    return 0;
}