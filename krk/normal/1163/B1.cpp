#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int u[Maxn];
int freq[Maxn];
map <int, int> M;

bool Check()
{
    if (M.size() == 1) return M.rbegin()->second == 1 || M.begin()->first == 1;
    else if (M.size() == 2)
        return M.rbegin()->second == 1 && M.begin()->first + 1 == M.rbegin()->first ||
               M.begin()->first == 1 && M.begin()->second == 1;
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &u[i]);
        freq[u[i]]++;
    }
    for (int i = 0; i < Maxn; i++) if (freq[i])
        M[freq[i]]++;
    for (int i = n; i > 0; i--) {
        if (Check()) { printf("%d\n", i); return 0; }
        int el = freq[u[i]];
        if (--M[el] == 0) M.erase(el);
        freq[u[i]]--;
        if (freq[u[i]] > 0) M[freq[u[i]]]++;
    }
    return 0;
}