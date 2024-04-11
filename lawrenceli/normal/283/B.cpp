#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
ll val[MAXN], a[MAXN];
bool vis[MAXN];

void dfs(int x) {
    if (val[x]!=-2) return;
    vis[x]=1;
    ll ox=x;
    ll y=a[x];
    x+=a[x];
    if (x>n) {
        val[ox]=y;
        vis[ox]=0;
        return;
    }
    y+=a[x];
    x-=a[x];
    if (x<=0) {
        val[ox]=y;
        vis[ox]=0;
        return;
    }
    if (vis[x]) {
        val[ox]=-1;
        vis[ox]=0;
        return;
    }
    dfs(x);
    if (val[x]==-1) {
        val[ox]=-1;
        vis[ox]=0;
        return;
    }
    val[ox]=val[x]+y;
    vis[ox]=0;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=2; i<=n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=n; i++) val[i]=-2;
    val[1]=-1;
    for (int i=2; i<=n; i++) {
        if (val[i]==-2) dfs(i);
    }
    for (int i=1; i<n; i++) {
        a[1]=i;
        int x=1;
        ll y=0;
        y+=a[x];
        x+=a[x];
        if (x>n) {
            cout << y << endl;
            continue;
        }
        y+=a[x];
        x-=a[x];
        if (x<=0) {
            cout << y << endl;
            continue;
        }
        if (val[x]==-1) cout << -1 << endl;
        else cout << val[x]+y << endl;
    }
}