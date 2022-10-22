#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
struct seg {
    seg* l;
    seg* r;
    int maxu,minv;
};
struct lect {
    int sa,ea,sb,eb;
};
int n;
lect a[maxn];
int sa[maxn],ea[maxn],sb[maxn],eb[maxn];
bool operator <(lect x,lect y) {
    return x.ea<y.ea || (x.ea==y.ea && x.sa<y.sa);
}
void add(seg* &rt,int i,int x,int y) {
    if(rt==NULL) {
        rt=(seg*)malloc(sizeof(seg));
        rt->l=rt->r=NULL;
        rt->maxu=0;
        rt->minv=2e9;
    }
    if(ea[i]>y || ea[i]<x) return;
    if(x==y) {
        rt->maxu=max(rt->maxu,sb[i]);
        rt->minv=min(rt->minv,eb[i]);
        return;
    }
    int m=(x+y)>>1;
    add(rt->l,i,x,m);
    add(rt->r,i,m+1,y);
    rt->maxu=max(rt->l->maxu,rt->r->maxu);
    rt->minv=min(rt->l->minv,rt->r->minv);
}
pair<int,int> query(seg* rt,int i,int x,int y) {
    if(rt==NULL || sa[i]>y || ea[i]<x) return {0,2e9};
    if(sa[i]<=x && y<=ea[i]) return {rt->maxu,rt->minv};
    int m=(x+y)>>1;
    pair<int,int> q1 =query(rt->l,i,x,m);
    pair<int,int> q2=query(rt->r,i,m+1,y);
    return {max(q1.first,q2.first),min(q1.second,q2.second)};
}
seg* rt;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d %d %d",&a[i].sa,&a[i].ea,&a[i].sb,&a[i].eb);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        sa[i]=a[i].sa;
        ea[i]=a[i].ea;
        sb[i]=a[i].sb;
        eb[i]=a[i].eb;
    }
    for(int i=0;i<n;i++) {
        pair<int,int> q=query(rt,i,0,2e9);
        if(sb[i]>q.second || eb[i]<q.first) {
            printf("NO");
            return 0;
        }
        add(rt,i,0,2e9);
    }
    rt=NULL;
    for(int i=0;i<n;i++) {
        swap(a[i].sa,a[i].sb);
        swap(a[i].ea,a[i].eb);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        sa[i]=a[i].sa;
        ea[i]=a[i].ea;
        sb[i]=a[i].sb;
        eb[i]=a[i].eb;
    }
    for(int i=0;i<n;i++) {
        pair<int,int> q=query(rt,i,0,2e9);
        if(sb[i]>q.second || eb[i]<q.first) {
            printf("NO");
            return 0;
        }
        add(rt,i,0,2e9);
    }
    printf("YES");
    return 0;
}