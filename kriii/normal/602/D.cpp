#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,Q,A[100010],V[100010],par[100010],chk[100010],sz[100010];

int find(int x)
{
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

int main()
{
    scanf ("%d %d",&N,&Q);
    for (int i=0;i<N;i++){
        scanf ("%d",&A[i]);
    }
    for (int i=1;i<N;i++){
        int abs = A[i-1] - A[i];
        if (abs < 0) abs = -abs;
        V[i] = abs;
    }

    for (int i=0;i<Q;i++){
        int l,r; scanf ("%d %d",&l,&r);
        long long s = 0;
        vector<pair<int, int> > vt;
        for (int j=l;j<r;j++){
            par[j] = j; chk[j] = 0;
            vt.push_back(make_pair(V[j],j));
        }
        par[l-1] = l-1; par[r] = r;
        chk[l-1] = chk[r] = 0;
        sort(vt.begin(),vt.end());
        for (auto p : vt){
            int j = p.second; long long v = p.first, c[2] = {1,1};
            chk[j] = 1; sz[j] = 1;
            for (int d=-1,u=0;d<=1;d+=2,u++){
                int k = find(j + d);
                if (chk[k]){
                    c[u] += sz[k];
                    sz[j] += sz[k];
                    par[k] = j;
                }
            }
            s += c[0] * c[1] * v;
        }
        printf ("%lld\n",s);
    }

    return 0;
}