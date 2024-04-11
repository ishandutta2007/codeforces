#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
map <int, int> M;

int Digs(int x)
{
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]--;
        }
        int res = 0;
        while (!M.empty()) {
            auto it = M.end(); it--;
            int key = it->first, val = it->second;
            M.erase(it++);
            if (val) {
                M[Digs(key)] += val;
                res += abs(val);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}