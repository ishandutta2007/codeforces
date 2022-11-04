#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct node {int t,l,r;};
bool operator < (const node &x,const node &y) {return x.t<y.t;}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        int n,m; scanf("%d%d",&n,&m);
        vector<node>a(n+1); a[0]=(node){0,m,m};
        rep(i,1,n) {
            int p,q,r; scanf("%d%d%d",&p,&q,&r);
            a[i]=(node){p,q,r};
        }
        sort(a.begin(),a.end());
        int l=a[0].l, r=a[0].r;
        bool flag=1;
        rep(i,1,n) {
            int l0=l-(a[i].t-a[i-1].t), r0=r+(a[i].t-a[i-1].t);
            l=max(l0,a[i].l), r=min(r0,a[i].r);
            if(l>r) {flag=0;break;}
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}