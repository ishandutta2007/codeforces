#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1e5;
int mabs(int x) {
    if (x<0) return -x;
    else return x;
}
long long f[maxn],nf[maxn];
int ll[maxn][3];
int n,x;
int v;
int d[maxn];
int calc(int l, int x, int r) {
    if (l<=x && x<=r) return 0;
    else return min(mabs(l-x),mabs(r-x));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    for (int i=1;i<=n;i++) {
        cin >> ll[i][1] >> ll[i][2];
        v++;
        d[v]=ll[i][1];
        v++;
        d[v]=ll[i][2];
    }
    v++;
    d[v]=x;
    sort(d+1,d+v+1);
    int g=0;
    for (int i=1;i<=v;i++)
    if (d[i]!=d[i-1]) {
        g++;
        d[g]=d[i];
    }
    v=g;
    for (int i=1;i<=v;i++)
        if (d[i]==x) f[i]=0;
        else f[i]=1e18;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=v;j++) nf[j]=1e18;
        long long mn=1e18;
        for (int j=1;j<=v;j++) {
            nf[j]=min(nf[j],min(f[j]+calc(ll[i][1],d[j],ll[i][2]),mn+d[j]+calc(ll[i][1],d[j],ll[i][2])));
            if (f[j]-d[j]<mn) mn=f[j]-d[j];
        }
        mn=1e18;
        for (int j=v;j>=1;j--) {
            nf[j]=min(min(f[j]+calc(ll[i][1],d[j],ll[i][2]),mn-d[j]+calc(ll[i][1],d[j],ll[i][2])),nf[j]);
            if (f[j]+d[j]<mn) mn=f[j]+d[j];
        }
        for (int j=1;j<=v;j++) f[j]=nf[j];
    }
    long long mn=1e18;
    for (int i=1;i<=v;i++)
        if (f[i]<mn) mn=f[i];
    cout << mn << "\n";
    return 0;
}