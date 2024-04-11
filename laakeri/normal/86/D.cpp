#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int h[1000001];
ll v=0;

int vs[200001];

int s=0;

ll vv[200001];

struct qr{
    int a,b;
    int i;
    bool operator<(const qr&q2) const{
        if (a/s!=q2.a/s) return a/s<q2.a/s;
        return b>q2.b;
    }
};

qr qs[200001];

int main(){
    int n,q;
    scanf("%i %i", &n, &q);
    s=sqrt(n);
    for (int i=0;i<n;i++){
        scanf("%i", &vs[i]);
    }
    for (int i=0;i<q;i++){
        int a,b;
        scanf("%i %i", &a, &b);
        a--;
        b--;
        qs[i].a=a;
        qs[i].b=b;
        qs[i].i=i;
    }
    sort(qs, qs+q);
    int l=-1;
    int r=-2;
    for (int ii=0;ii<q;ii++){
        for (int i=l;i<qs[ii].a&&i<=r;i++){
            int x=vs[i];
            v-=(ll)h[x]*h[x]*x;
            h[x]--;
            v+=(ll)h[x]*h[x]*x;
        }
        for (int i=r;i>qs[ii].b&&i>=l;i--){
            int x=vs[i];
            v-=(ll)h[x]*h[x]*x;
            h[x]--;
            v+=(ll)h[x]*h[x]*x;
        }
        for (int i=qs[ii].a;i<l&&i<=qs[ii].b;i++){
            int x=vs[i];
            v-=(ll)h[x]*h[x]*x;
            h[x]++;
            v+=(ll)h[x]*h[x]*x;
        }
        for (int i=qs[ii].b;i>r&&i>=qs[ii].a;i--){
            int x=vs[i];
            v-=(ll)h[x]*h[x]*x;
            h[x]++;
            v+=(ll)h[x]*h[x]*x;
        }
        l=qs[ii].a;
        r=qs[ii].b;
        vv[qs[ii].i]=v;
    }
    for (int i=0;i<q;i++){
        printf("%I64d\n", vv[i]);
    }
}