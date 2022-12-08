#include <stdio.h>
#include <algorithm>
using namespace std;

int N,a,b,c,t[200002],ans;
int n,tmp[200002];

void bye(int p, int q, int r)
{
    if (p > q) return;
    int count = upper_bound(t,t+N,q) - lower_bound(t,t+N,p);
    ans += count;

    n = 0;
    int upp = upper_bound(t,t+N,r) - t;
    int gg = min(upp,count);
    for (int i=0;i<upp-gg;i++) tmp[n++] = t[i];
    for (int i=upp;i<N;i++) if (t[i] < p) tmp[n++] = t[i];
    for (int i=0;i<n;i++) t[i] = tmp[i];
    N = n;
}

bool chk(int m)
{
    int upp = upper_bound(t,t+N,c) - t;
    int gg = min(upp,m);
    n = 0;
    for (int i=0;i<upp-gg;i++) tmp[n++] = t[i];
    for (int i=upp;i<N;i++) tmp[n++] = t[i];
    if (n == 0) return true;
    if (tmp[n-1] > a + b) return false;
    
    int u = upper_bound(tmp,tmp+n,a) - tmp;
    int v = upper_bound(tmp,tmp+n,b) - tmp;
    int w = n;
    for (int x=0;x<=m;x++){
        if (w - v > x) continue;
        int r1 = x - (w - v);
        if (v - u - r1 > m - x) continue;
        int r2 = m - x - (v - u - r1);
        if (u - r2 > m - x) continue;
        return true;
    }
    return false;
}

int main()
{
    scanf ("%d %d %d %d",&N,&a,&b,&c);
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);

    for (int i=0;i<N;i++){
        scanf ("%d",&t[i]);
        if (t[i] > a+b+c){
            puts("-1");
            return 0;
        }
        if (t[i] > b+c){
            N--; i--; ans++;
        }
    }

    sort(t,t+N);
    bye(a+c+1,b+c,a);
    if (a+b <= c) bye(c+1,a+c,b);
    else bye(a+b+1,a+c,b);

    int l = 0, r = N, g = N+1;
    while (l <= r){
        int m = (l + r) / 2;
        if (chk(m)){
            g = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    ans += g;

    printf ("%d\n",ans);

    return 0;
}