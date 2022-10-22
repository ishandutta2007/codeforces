#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200001;

int n, k;
int freq[Maxn];
vector <int> res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    int lef = 1, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        int col = 0;
        for (int i = 1; i < Maxn; i++)
            col += freq[i] / mid;
        if (col >= k) lef = mid + 1;
        else rig = mid - 1;
    }
    lef--;
    for (int i = 1; i < Maxn; i++)
        while (freq[i] >= lef && res.size() < k) {
            res.push_back(i);
            freq[i] -= lef;
        }
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}