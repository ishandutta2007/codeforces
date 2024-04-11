#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int t;
int n;
int a[Maxn];

bool Check(int l, int r, int x)
{
    while (l < r)
        if (a[l] == a[r]) l++, r--;
        else if (a[l] == x) l++;
        else if (a[r] == x) r--;
        else return false;
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int l = 0, r = n - 1;
        while (l < r && a[l] == a[r]) {
            l++; r--;
        }
        if (l >= r) printf("YES\n");
        else if (Check(l, r, a[l]) || Check(l, r, a[r])) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}