#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n;
int t;
int a[maxn];
int pg[maxn];
int ng[maxn];
int lid[20*maxn];
int rid[20*maxn];
int val[20*maxn];
int rt[maxn];
int sz=1;
int mx(int id,int l,int r,int p) {
    if(id==0) return 0;
    if(p<l) return 0;
    if(r<=p) return val[id];
    int m=(l+r)/2;
    return max(mx(lid[id],l,m,p),mx(rid[id],m+1,r,p));
}
void add(int id,int l,int r,int p,int v) {
    int cur=sz;
    sz++;
    //cout<<id<<" "<<cur<<" "<<l<<" "<<r<<" "<<p<<" "<<v<<endl;
    lid[cur]=lid[id];
    rid[cur]=rid[id];
    val[cur]=val[id];
    val[cur]=max(val[cur],v);
    if(l==r) return;
    int m=(l+r)/2;
    if(p<=m) {
        lid[cur]=cur+1;
        add(lid[id],l,m,p,v);
    }
    else {
        rid[cur]=cur+1;
        add(rid[id],m+1,r,p,v);
    }
    val[cur]=max(val[lid[cur]],val[rid[cur]]);
    //cout<<cur<<" "<<lid[cur]<<" "<<rid[cur]<<" "<<val[cur]<<endl;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        pg[0]=-1;
        for(int i=1;i<n;i++) {
            pg[i]=i-1;
            while(pg[i]>=0 && a[pg[i]]<=a[i]) pg[i]=pg[pg[i]];
        }
        ng[n-1]=n;
        for(int i=n-2;i>=0;i--) {
            ng[i]=i+1;
            while(ng[i]<n && a[ng[i]]<=a[i]) ng[i]=ng[ng[i]];
        }
        for(int i=0;i<n;i++) {
            int j=pg[i];
            int cv=1;
            if(i!=0) {
                cv=max(cv,mx(rt[i-1],1,n,a[i])+1);
            }
            if(j!=-1) {
                //cout<<" "<<i<<" "<<j<<endl;
                cv=max(cv,mx(rt[j],1,n,a[i])+2);
            }
            if(i==0) {
                rt[i]=sz;
                add(0,1,n,a[i],cv);
            }
            else {
                rt[i]=sz;
                add(rt[i-1],1,n,a[i],cv);
            }
            //cout<<i<<" "<<cv<<endl;
            ans=max(ans,cv);
        }
        printf("%d\n",ans);
        for(int i=0;i<=sz;i++) {
            lid[i]=rid[i]=val[i]=0;
        }
        for(int i=0;i<n;i++) {
            rt[i]=0;
        }
        sz=1;
    }
    return 0;
}