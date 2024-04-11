#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int b[Maxn];

void Trivial(int fir, int sec, int thir)
{
    if (abs(a[fir] + a[sec]) > 10000) {
        b[thir] = a[fir] - a[sec];
        b[sec] = a[thir];
        b[fir] = -a[thir];
    } else {
        b[thir] = a[fir] + a[sec];
        b[sec] = -a[thir];
        b[fir] = -a[thir];
    }
}

void Solve3(int fir, int sec, int thir)
{
    if (abs(a[fir]) != abs(a[sec])) Trivial(fir, sec, thir);
    else if (abs(a[fir]) != abs(a[thir])) Trivial(fir, thir, sec);
    else if (abs(a[sec]) != abs(a[thir])) Trivial(sec, thir, fir);
    else if (a[fir] > 0 && a[sec] > 0 && a[thir] > 0 ||
             a[fir] < 0 && a[sec] < 0 && a[thir] < 0) {
        b[fir] = 2;
        b[sec] = -1;
        b[thir] = -1;
    } else {
        int pos = int(a[fir] > 0) + int(a[sec] > 0) + int(a[thir] > 0);
        int neg = 3 - pos;
        b[fir] = a[fir] > 0? neg: pos;
        b[sec] = a[sec] > 0? neg: pos;
        b[thir] = a[thir] > 0? neg: pos;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int lim = n;
        if (n % 2) {
            Solve3(n - 3, n - 2, n - 1);
            lim -= 3;
        }
        for (int i = 0; i + 1 < lim; i += 2) {
            b[i] = a[i + 1];
            b[i + 1] = -a[i];
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", b[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}