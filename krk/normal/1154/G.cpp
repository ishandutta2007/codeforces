#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxm = 10000007;
const int Maxn = 1000005;

int n;
int a[Maxn];
vector <int> V[Maxm];
int tmp[2], tlen;
ll res = 1000000000000000000ll;
int bi, bj;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (V[a[i]].size() < 2) V[a[i]].push_back(i);
    }
    for (int i = 1; i < Maxm; i++) {
        tlen = 0;
        for (int j = i; j < Maxm && tlen < 2; j += i) {
            if (!V[j].empty()) tmp[tlen++] = V[j][0];
            if (V[j].size() >= 2 && tlen < 2) tmp[tlen++] = V[j][1];
        }
        if (tlen >= 2) {
            ll cand = ll(a[tmp[0]]) / i * ll(a[tmp[1]]);
            if (cand < res) { res = cand; bi = tmp[0]; bj = tmp[1]; }
        }
    }
    if (bi > bj) swap(bi, bj);
    printf("%d %d\n", bi, bj);
    return 0;
}