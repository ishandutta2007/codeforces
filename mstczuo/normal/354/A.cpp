# include <iostream>
# include <cstdio>
using namespace std;

int n, d, l, r, ql, qr, a[100010], ans = ~0U>>1;

int get()
{
    if (d==0) return 0;
    if (d>0) return ql * (d-1);
    if (d<0) return qr * (-d-1);
}

int main()
{
    scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr); d = -n;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) a[i] += a[i-1];
    for(int i=0; i<=n; i++, d+=2)
        ans = min(ans, a[i] * l + (a[n]-a[i]) * r + get());
    cout << ans << endl; return 0;
}