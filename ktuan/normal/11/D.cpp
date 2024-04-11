#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
bool a[19][19];
long long F[19][1<<19];
int id[1<<19];

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u-1][v-1] = true;
        a[v-1][u-1] = true;
    }
    for(int i=0;i<n;++i) id[1<<i] = i;
    for(int i=0;i<n;++i) F[i][1<<i] = 1;
    
    for(int bit=0;bit<((1<<n)-1);++bit) {
        for(int last=0;last<n;++last) {
            long long tmp;
            if((tmp = F[last][bit]) > 0) {
                int firstbit = id[bit & (-bit)];
                for(int ad=firstbit+1;ad<n;++ad) if((bit&(1<<ad))==0 && a[last][ad]) {
                    F[ad][bit | (1<<ad)] += tmp;
                }
            }
        }
    }
    long long res = 0;
    for(int bit=0;bit<1<<n;++bit) {
    int c = 0;
    for(int i=0;i<n;++i) if((bit&(1<<i))!=0) ++c;
    if(c <= 2) continue;
    for(int l=0;l<n;++l) if(F[l][bit] > 0) {
        int f = id[bit & (-bit)];
        if(a[f][l]) res += F[l][bit];
    }
    }
    cout << res / 2 << endl;
    return 0;
}