#include<bits/stdc++.h>
using namespace std;
int n;
int a[200000];
int pv[200000];
int ans[200000];
int f(int i) {
    if(i==n-1) return 0;
    else return i+1;
}
int p(int i) {
    if(i==0) return n-1;
    else return i-1;
}
int dist(int i,int j) {
    if(j>i) return j-i;
    else return n-i+j;
}
bool cond(int v1,int v2) {
    if(v1%2==0) {
        if(v2<v1/2) return true;
        return false;
    }
    else {
        if(v2<v1/2+1) return true;
        return false;
    }
}
struct seg {
    seg* l;
    seg* r;
    int vl;
};
seg* rt=NULL;
void ins(seg* &ind,int l,int r,int x,int v) {
    if(ind==NULL) {
        ind=new seg();
        ind->l=ind->r=NULL;
        ind->vl=0;
    }
    if(l==r) {
        ind->vl=min(ind->vl,v);
        return;
    }
    int m=(l+r)/2;
    if(x<=m) ins(ind->l,l,m,x,v);
    else ins(ind->r,m+1,r,x,v);
    ind->vl=min(ind->l==NULL ? 0 : ind->l->vl,ind->r==NULL ? 0 : ind->r->vl);
}
int val(seg* ind,int l,int r,int x) {
    if(ind==NULL) return 0;
    if(x>=r) return ind->vl;
    int m=(l+r)/2;
    if(x<=m) return val(ind->l,l,m,x);
    else return min(val(ind->l,l,m,x),val(ind->r,m+1,r,x));
}
int main() {

    int maxv,minv;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    maxv=minv=a[0];
    for(int i=1;i<n;i++) {
        maxv=max(maxv,a[i]);
        minv=min(minv,a[i]);
    }
    if(maxv%2==0) {
        if(minv>=maxv/2) {
            for(int i=0;i<n;i++) {
                printf("-1 ");
            }
            return 0;
        }
    }
    else {
        if(minv>=maxv/2+1) {
            for(int i=0;i<n;i++) {
                printf("-1 ");
            }
            return 0;
        }
    }
    int mi=0;
    for(int i=0;i<n;i++) {
        if(a[i]==maxv) mi=i;
    }
    int i=p(mi);
    pv[mi]=mi;
    for(int t=0;t<n-1;t++) {
        int j=f(i);
        while(a[j]<a[i]) j=pv[j];
        pv[i]=j;
        i=p(i);
    }
    i=f(mi);
    int t=1;
    while(true) {
        if(maxv%2==0) {
            if(a[i]<maxv/2) {
                ans[mi]=t;
                break;
            }
        }
        else {
            if(a[i]<maxv/2+1) {
                ans[mi]=t;
                break;
            }
        }
        i=f(i);
        t++;
    }
    i=p(mi);
    int ct;
    int pt;
    for(int t=0;t<n-1;t++) {
        int j=f(i);
        if(a[j]>=a[i]) {
            ans[i]=ans[j]+1;
        }
        else {
            int vl;
            if(a[i]%2==0) vl=a[i]/2-1;
            else vl=a[i]/2;
            int pt=val(rt,0,1e9,vl);
            if(pt!=0) ans[i]=min(ans[pv[i]]+dist(i,pv[i]),dist(i,(mi+pt+n)%n));
            else ans[i]=ans[pv[i]]+dist(i,pv[i]);
        }
        ins(rt,0,1e9,a[i],-(t+1));
        i=p(i);
    }
    for(int i=0;i<n;i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}