#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

vector <int> dvs[Maxn];
int my[Maxn];
ll tmp[Maxn];
int cur[Maxn];
int res = Maxn;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int main()
{
    for (int i = 1; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            dvs[j].push_back(i);
    int n; scanf("%d", &n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        int num; scanf("%d", &num);
        g = gcd(g, num); cur[num] = 1;
        if (num == 1) { printf("1\n"); return 0; }
    }
    if (g > 1) { printf("-1\n"); return 0; }
    for (int i = 1; i < Maxn; i++)
        if (cur[i])
            for (int j = 0; j < dvs[i].size(); j++)
                my[dvs[i][j]]++;
    for (int i = 2; ; i++) {
        fill(tmp, tmp + Maxn, 0ll);
        for (int j = Maxn - 1; j > 0; j--) if (cur[j] == i - 1)
            for (int l = 0; l < dvs[j].size(); l++) {
                int d = dvs[j][l];
                tmp[d] += my[d];
            }
        for (int j = Maxn - 1; j > 0; j--) {
            for (int l = j + j; l < Maxn; l += j)
                tmp[j] -= tmp[l];
            if (!cur[j] && tmp[j] > 0) cur[j] = i;
        }
        if (cur[1]) { printf("%d\n", i); break; }
    }
    return 0;
}