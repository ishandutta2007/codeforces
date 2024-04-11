#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> res;
        res.push_back(1); n--;
        while (true)
            if (2 * res.back() >= n) { res.push_back(n); break; }
            else {
                int nxt = min(n / 2, 2 * res.back());
                res.push_back(nxt); n -= nxt;
            }
        printf("%d\n", int(res.size()) - 1);
        for (int i = 1; i < res.size(); i++)
            printf("%d%c", res[i] - res[i - 1], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}