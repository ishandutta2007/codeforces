#include <bits/stdc++.h>
using namespace std;

int n, k;
map <int, int> M;
int cur, res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        M[a]++;
    }
    while (M.size() > 1) {
        auto it = M.end(); it--;
        int key = it->first;
        int val = it->second; M.erase(it);
        if (cur + val <= k) cur += val;
        else { res++; cur = val; }
        M[key - 1] += val;
    }
    if (cur) res++;
    printf("%d\n", res);
    return 0;
}