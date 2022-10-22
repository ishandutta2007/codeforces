#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int freq[Maxn];
int best, bi, bj;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    int lef = 0;
    while (lef < Maxn)
        if (freq[lef] == 0) lef++;
        else {
            int all = 0;
            int rig = lef;
            while (rig < Maxn)
                if (freq[rig] == 0) { rig--; break; }
                else if (freq[rig] == 1 && lef != rig) { all += freq[rig]; break; }
                else { all += freq[rig]; rig++; }
            if (rig == Maxn) rig--;
            if (all > best) {
                best = all; bi = lef; bj = rig;
            }
            if (lef == rig || freq[rig] > 1) lef = rig + 1;
            else lef = rig;
        }
    vector <int> res;
    for (int i = bi; i <= bj; i++) {
        res.push_back(i); freq[i]--;
    }
    for (int i = bj; i >= bi; i--)
        while (freq[i]--) res.push_back(i);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}