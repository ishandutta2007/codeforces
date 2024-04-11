#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

const int Z = 1<<19;
int x[Z*2];

int N,M,l[200020],r[200020],a[200020],b[200020]; long long c[200020];
struct intv{
    long long l,r; int t,i;
    bool operator <(const intv tt) const{
        if (r != tt.r) return r < tt.r;
        return t < tt.t;
    }
}I[400020];

struct mxi{
    mxi(){mx = -1e12, in = -1;}
    mxi(long long mx_, int in_){mx = mx_; in = in_;}
    long long mx; int in;

    bool operator <(const mxi t) const{
        return mx < t.mx;
    }
}BIT[2][400020];

void in(mxi *bit, mxi p, int x, int c)
{
    while (x <= c){
        if (bit[x] < p)
            bit[x] = p;
        x += x & (-x);
    }
}

mxi out(mxi *bit, int x)
{
    mxi res;
    while (x){
        if (res < bit[x])
            res = bit[x];
        x -= x & (-x);
    }
    return res;
}

long long ans; int pp,qq;

void go()
{
    map<int, int> rem;
    for (int i=0;i<N;i++) rem[l[i]] = 0;
    for (int i=0;i<M;i++) rem[a[i]] = 0;
    int C = 0;
    for (auto &p : rem) p.second = ++C;
    int V = 0;
    for (int i=0;i<N;i++){
        I[V].l = l[i]; I[V].r = r[i]; I[V].t = 0; I[V].i = i; V++;
    }
    for (int i=0;i<M;i++){
        I[V].l = a[i]; I[V].r = b[i]; I[V].t = 1; I[V].i = i; V++;
    }
    sort(I,I+V);
    for (int i=0;i<=C;i++){
        BIT[0][i] = BIT[1][i] = mxi();
    }
    for (int i=0;i<V;i++){
        int p = rem[I[i].l];
        if (I[i].t == 0){
            in(BIT[0],mxi(I[i].r,I[i].i),p,C);
            in(BIT[1],mxi(I[i].r-I[i].l,I[i].i),C-p+1,C);
        }
        else{
            mxi aa = out(BIT[0],p); aa.mx -= I[i].l;
            mxi bb = out(BIT[1],C-p+1);
            mxi w = aa < bb ? bb : aa;
            if (w.in == -1) continue;
            if (ans < w.mx * c[I[i].i]){
                ans = w.mx * c[I[i].i];
                pp = w.in+1; qq = I[i].i+1;
            }
        }
    }
}

void go2()
{
    map<int, int> rem;
    for (int i=0;i<N;i++) rem[l[i]] = 0;
    for (int i=0;i<M;i++) rem[a[i]] = 0;
    int C = 0;
    for (auto &p : rem) p.second = ++C;
    int V = 0;
    for (int i=0;i<N;i++){
        I[V].l = l[i]; I[V].r = r[i]; I[V].t = 1; I[V].i = i; V++;
    }
    for (int i=0;i<M;i++){
        I[V].l = a[i]; I[V].r = b[i]; I[V].t = 0; I[V].i = i; V++;
    }
    sort(I,I+V);
    for (int i=0;i<=C;i++) BIT[1][i] = mxi();

    for (int i=0;i<V;i++){
        int p = rem[I[i].l];
        if (I[i].t == 0){
            in(BIT[1],mxi((I[i].r-I[i].l)*c[I[i].i],I[i].i),C-p+1,C);
        }
        else{
            mxi w = out(BIT[1],C-p+1);
            if (w.in == -1) continue;
            if (ans < w.mx){
                ans = w.mx;
                qq = w.in+1; pp = I[i].i+1;
            }
        }
    }
}

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=0;i<N;i++){
        scanf ("%d %d",&l[i],&r[i]);
    }
    for (int i=0;i<M;i++){
        scanf ("%d %d %lld",&a[i],&b[i],&c[i]);
    }

    for (int k=0;k<2;k++){
        go();
        for (int i=0;i<N;i++){
            l[i] *= -1; r[i] *= -1; swap(l[i],r[i]);
        }
        for (int i=0;i<M;i++){
            a[i] *= -1; b[i] *= -1; swap(a[i],b[i]);
        }
    }
    go2();

    printf ("%lld\n",ans);
    if (ans) printf ("%d %d\n",pp,qq);

    return 0;
}