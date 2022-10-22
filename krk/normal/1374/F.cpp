#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector <int> res;

void Apply(int x)
{
    res.push_back(x);
    int tmp = a[x + 2];
    a[x + 2] = a[x + 1];
    a[x + 1] = a[x];
    a[x] = tmp;
}

void Print()
{
    printf("%d\n", int(res.size()));
    bool was = false;
    for (int i = 0; i < res.size(); i++) {
        if (was) printf(" ");
        else was = true;
        printf("%d", res[i] + 1);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int inv = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < i; j++)
                if (a[j] > a[i]) inv++;
            b[i] = a[i];
        }
        sort(b, b + n);
        int sam = -1;
        for (int i = 0; i + 1 < n; i++)
            if (b[i] == b[i + 1]) { sam = b[i]; break; }
        if (sam == -1 && inv % 2) { printf("-1\n"); continue; }
        if (sam == -1) sam = 505;
        res.clear();
        for (int i = 0; i < n && b[i] < sam; i++) if (a[i] != b[i]) {
            int pnt = i;
            while (a[pnt] != b[i]) pnt++;
            while (pnt - 2 >= i) {
                Apply(pnt - 2);
                pnt -= 2;
            }
            if (pnt - 1 == i) {
                Apply(i);
                Apply(i);
            }
        }
        for (int i = n - 1; i >= 0 && b[i] > sam; i--) if (a[i] != b[i]) {
            int pnt = i;
            while (a[pnt] != b[i]) pnt--;
            while (pnt + 2 <= i) {
                Apply(pnt);
                pnt++;
            }
            if (pnt + 1 == i)
                Apply(pnt - 1);
        }
        Print();
    }
    return 0;
}