#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int f[Maxn];
bool in[Maxn];
vector <ii> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        if (f[i]) in[f[i]] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!in[i]) {
            int num = i;
            while (f[num] != 0) num = f[num];
            seq.push_back(ii(i, num));
        }
    for (int i = 0; i < seq.size(); i++) {
        int ni = (i + 1) % int(seq.size());
        f[seq[i].second] = seq[ni].first;
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", f[i], i + 1 <= n? ' ': '\n');
    return 0;
}