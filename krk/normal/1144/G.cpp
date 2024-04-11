#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int freq[Maxn];
int my[Maxn];

int getStatus(int x)
{
    vector <int> res1, res2;
    int i = 0;
    int st = 0;
    while (i < n) {
        if (a[i] < x)
            if (res2.empty() || a[res2.back()] < a[i]) res2.push_back(i);
            else { st = -1; break; }
        else if (res1.empty() || a[res1.back()] > a[i]) res1.push_back(i);
             else { st = 1; break; }
        i++;
    }
    for (; i < n; i++)
        if (res2.empty() || a[res2.back()] < a[i]) res2.push_back(i);
        else if (res1.empty() || a[res1.back()] > a[i]) res1.push_back(i);
        else return st;
    fill(my, my + n, 0);
    for (int i = 0; i < res1.size(); i++)
        my[res1[i]] = 1;
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    for (int i = 0; i < Maxn; i++)
        if (freq[i] > 2) { printf("NO\n"); return 0; }
    int lef = 0, rig = 200005;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        int st = getStatus(mid);
        if (st == 0) {
            printf("YES\n");
            for (int i = 0; i < n; i++)
                printf("%d%c", my[i], i + 1 < n? ' ': '\n');
            return 0;
        } else if (st > 0) lef = mid + 1;
        else rig = mid - 1;
    }
    printf("NO\n");
    return 0;
}