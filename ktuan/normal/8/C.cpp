#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))

int sx, sy;
int n;
int x[25], y[25];
int dist[25][25];
int d[25];

int F[1<<24], T[1<<24];

void truy(int mask) {
    if(mask == 0) return;
    int l = 0;
    for(int i=0;i<n;++i) if((mask & (1<<i))!=0) l = i;
    if(T[mask] == -1) {
        cout << (l+1) << " " << 0 << " ";
        truy( mask ^ (1<<l) );
    }
    else {
        int k = T[mask];
        cout << l+1 << " " << k + 1 << " 0 ";
        truy(mask ^ (1<<l) ^ (1<<k));
    }
}

int main() {
    cin >> sx >> sy;
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> x[i] >> y[i];
    for(int i=0;i<n;++i) d[i] = 2 * (sqr(x[i]-sx) + sqr(y[i]-sy));
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            dist[i][j] = dist[j][i] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(x[i]-sx) + sqr(y[i]-sy) + sqr(x[j]-sx) + sqr(y[j]-sy);
    F[0] = 0;
    for(int i=1;i<1<<n;++i) {
        F[i] = 1000000000;
        int z = 0, l = 0;
        for(int j=0;j<n;++j) if((i&(1<<j))!=0) {
            ++z;
            l = j;
        }
        
        {
            int tmp = F[i ^ (1<<l)] + d[l];
            if(F[i] > tmp) {
                F[i] = tmp;
                T[i] = -1;
            }
        }
        for(int j=0;j<l;++j) if((i&(1<<j))!=0)
        {
            int tmp = F[i ^ (1<<j) ^ (1<<l)] + dist[j][l];
            if(F[i] > tmp) {
                F[i] = tmp;
                T[i] = j;
            }
        }
    }
    cout << F[(1<<n)-1] << endl;
    cout << "0 ";
    truy( (1<<n) - 1);
    return 0;
}