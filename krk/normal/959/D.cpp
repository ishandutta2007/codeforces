#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 5000005;

int n;
bool inv[Maxm];
int mx[Maxm];
int a[Maxn];
int b[Maxn];

void Invalidate(int x)
{
    if (inv[x]) return;
    for (int i = x; i < Maxm; i += x)
        inv[i] = true;
}

void invalidateAll(int x)
{
    while (x > 1) {
        Invalidate(mx[x]);
        x /= mx[x];
    }
}

void fillFrom(int ind)
{
    int pnt = 2;
    for (int i = ind; i < n; i++) {
        while (inv[pnt]) pnt++;
        b[i] = pnt; invalidateAll(pnt);
    }
}

int main() {
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
        for (int j = i; j < Maxm; j += i) mx[j] = i;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        if (a[i] == 1 || inv[a[i]]) {
            int pnt = a[i] + 1;
            while (inv[pnt]) pnt++;
            b[i] = pnt; invalidateAll(pnt);
            fillFrom(i + 1);
            break;
        } else { b[i] = a[i]; invalidateAll(a[i]); }
    for (int i = 0; i < n; i++)
        printf("%d%c", b[i], i + 1 < n? ' ': '\n');
	return 0;
}