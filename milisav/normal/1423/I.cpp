#include<bits/stdc++.h>
#define maxq 200010
using namespace std;
long long l[maxq];
long long r[maxq];
int v[maxq];
int q;
long long k;
int lseg[4*maxq];
int rseg[4*maxq];
int seg[4*maxq];
int lstable[maxq];
int mstable[maxq];
void add_lor(int id,int l,int r,int x,int y,int v) {
    if(x<=l && r<=y) {
        lseg[id]|=v;
        return;
    }
    if(r<x || y<l) return;
    int m=(l+r)>>1;
    add_lor(id*2+1,l,m,x,y,v);
    add_lor(id*2+2,m+1,r,x,y,v);
}
void add_ror(int id,int l,int r,int x,int y,int v) {
    if(x<=l && r<=y) {
        rseg[id]|=v;
        return;
    }
    if(r<x || y<l) return;
    int m=(l+r)>>1;
    add_ror(id*2+1,l,m,x,y,v);
    add_ror(id*2+2,m+1,r,x,y,v);
}
void traverse_lseg(int id,int l,int r,int v) {
    if(l==r) {
        lstable[l]=v|lseg[id];
        return;
    }
    int m=(l+r)>>1;
    traverse_lseg(id*2+1,l,m,v|lseg[id]);
    traverse_lseg(id*2+2,m+1,r,v|lseg[id]);
}
void traverse_rseg(int id,int l,int r,int v) {
    if(l==r) {
        mstable[l]=v|rseg[id];
        return;
    }
    int m=(l+r)>>1;
    traverse_rseg(id*2+1,l,m,v|rseg[id]);
    traverse_rseg(id*2+2,m+1,r,v|rseg[id]);
}
void create_or_seg(int id,int l,int r) {
    if(l==r) {
        seg[id]=lstable[l];
        return;
    }
    int m=(l+r)>>1;
    create_or_seg(id*2+1,l,m);
    create_or_seg(id*2+2,m+1,r);
    seg[id]=seg[id*2+1]|seg[id*2+2];
}
int orint(int id,int l,int r,int x,int y) {
    if(x<=l && r<=y) return seg[id];
    if(r<x || y<l) return 0;
    int m=(l+r)>>1;
    return orint(id*2+1,l,m,x,y)|orint(id*2+2,m+1,r,x,y);
}
long long msk1,msk2;
long long n;
vector<pair<long long,pair<int,int> > > inters;
int main() {
    scanf("%lld %d",&k,&q);
    for(int i=0;i<q;i++) {
        scanf("%lld %lld %d",&l[i],&r[i],&v[i]);
        inters.push_back({l[i],{-1,v[i]}});
        inters.push_back({r[i],{1,v[i]}});
    }
    sort(inters.begin(),inters.end());
    int ci=0;
    int cv=0;
    long long cl=0;
    q=0;
    for(int i=0;i<inters.size();i++) {
        ci-=inters[i].second.first;
        if(ci==0) {
            l[q]=cl;
            r[q]=inters[i].first;
            v[q++]=inters[i].second.second;
        }
        else {
            if(ci==1 && inters[i].second.first==-1) {
                cl=inters[i].first;
                cv=inters[i].second.second;
            }
            else {
                if(cv!=inters[i].second.second) {
                    printf("impossible");
                    return 0;
                }
            }
        }
    }
    n=1ll<<k;
    msk1=(1ll<<k)-1ll;
    msk2=(1ll<<(2ll*k))-(1ll<<k);
    for(int i=0;i<q;i++) {
        if((l[i]&msk2)==(r[i]&msk2)) {
            add_lor(0,0,n-1,l[i]&msk1,r[i]&msk1,v[i]);
            add_ror(0,0,n-1,(l[i]&msk2)>>k,(l[i]&msk2)>>k,v[i]);
        }
        else {
            long long lb=(l[i]&msk2)>>k;
            long long rb=(r[i]&msk2)>>k;
            add_ror(0,0,n-1,lb,rb,v[i]);
            if(rb-lb>1) add_lor(0,0,n-1,0,n-1,v[i]);
            else {
                add_lor(0,0,n-1,0,r[i]&msk1,v[i]);
                add_lor(0,0,n-1,l[i]&msk1,n-1,v[i]);
            }
        }
    }
    traverse_lseg(0,0,n-1,0);
    traverse_rseg(0,0,n-1,0);
    create_or_seg(0,0,n-1);
    for(int i=0;i<q;i++) {
        //cout<<i<<endl;
        if((l[i]&msk2)==(r[i]&msk2)) {
            int cv=mstable[((l[i]&msk2)>>k)];
            int ov=orint(0,0,n-1,l[i]&msk1,r[i]&msk1);
            //cout<<cv<<" "<<ov<<" "<<v[i]<<endl;
            if((cv&ov)!=v[i]) {
                printf("impossible");
                return 0;
            }
        }
        else {
            int cv=mstable[((l[i]&msk2)>>k)];
            int ov=orint(0,0,n-1,l[i]&msk1,n-1);
            //cout<<cv<<" "<<ov<<" "<<v[i]<<endl;
            if((cv&ov)!=v[i]) {
                printf("impossible");
                return 0;
            }
            cv=mstable[((r[i]&msk2)>>k)];
            ov=orint(0,0,n-1,0,r[i]&msk1);
            //cout<<(r[i]&msk1)<<endl;
            //cout<<cv<<" "<<ov<<" "<<v[i]<<endl;
            if((cv&ov)!=v[i]) {
                printf("impossible");
                return 0;
            }
            long long lb=(l[i]&msk2)>>k;
            long long rb=(r[i]&msk2)>>k;
            for(long long j=lb+1;j<rb;j++) {
                int cv=mstable[j];
                int ov=orint(0,0,n-1,0,n-1);
                //cout<<cv<<" "<<ov<<" "<<v[i]<<endl;
                if((cv&ov)!=v[i]) {
                    printf("impossible");
                    return 0;
                }
            }
        }
    }
    printf("possible\n");
    for(int i=0;i<n;i++) printf("%d\n",lstable[i]);
    for(int i=0;i<n;i++) printf("%d\n",mstable[i]);
    return 0;
}