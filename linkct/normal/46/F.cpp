#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct Data {
    int x,y;
};

map<string,int> mp;
Data e[1010];
int pl[1010],fa[1010];
bool v[1010],v1[1010];

int find(int x) {
    return x == fa[x]?x:fa[x] = find(fa[x]);
}

int main() {
    int n,m,kk;
    scanf("%d%d%d",&n,&m,&kk);
    for (int i = 1; i <= m; i++)
        scanf("%d%d",&e[i].x,&e[i].y);
    for (int i = 0; i < kk; i++) {
        string s;
        cin >> s;
        int k,tmp;
        scanf("%d%d",&k,&tmp);
        mp[s] = k;
        for (int j = 0; j < tmp; j++) {
            int x;
            scanf("%d",&x);
            pl[x] = k;
        }
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (bool flag = 1; flag;) {
        flag = 0;
        for (int i = 1; i <= m; i++)
            if (! v[i] && (find(pl[i]) == find(e[i].x) || find(pl[i]) == find(e[i].y))) {
                flag = v[i] = 1;
                fa[find(e[i].x)] = find(e[i].y);
            }
    }
    for (int i = 1; i <= kk; i++) {
        string s;
        cin >> s;
        int k,tmp;
        scanf("%d%d",&k,&tmp);
        if (find(mp[s]) != find(k)) {
            printf("NO\n");
            return 0;
        }
        for (int j = 0; j < tmp; j++) {
            int x;
            scanf("%d",&x);
            if (find(k) != find(pl[x])) {
                printf("NO\n");
                return 0;
            }
            pl[x] = k;
        }
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (bool flag = 1; flag;) {
        flag = 0;
        for (int i = 1; i <= m; i++)
            if (! v1[i] && (find(pl[i]) == find(e[i].x) || find(pl[i]) == find(e[i].y))) {
                flag = v1[i] = 1;
                fa[find(e[i].x)] = find(e[i].y);
            }
    }
    for (int i = 1; i <= m; i++)
        if (v[i] != v1[i]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}