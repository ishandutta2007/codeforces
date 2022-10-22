#include<bits/stdc++.h>
using namespace std;
int seg[2000000];
int v[2000000];
struct val {
    int v;
    int ind;
};
void insert(int id,int l,int r,int a,int p) {
    if(l==r) {
        seg[id]=1;
        v[id]=a;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) insert(id*2+1,l,m,a,p);
    else insert(id*2+2,m+1,r,a,p);
    seg[id]=seg[id*2+1]+seg[id*2+2];
}
int kth(int id,int l,int r,int k) {
    if(l==r) return v[id];
    int m=(l+r)>>1;
    if(seg[id*2+1]>=k) return kth(id*2+1,l,m,k);
    else return kth(id*2+2,m+1,r,k-seg[id*2+1]);
}
bool operator <(val a,val b) {
    return a.v>b.v || (a.v==b.v && a.ind<b.ind);
}
val d[500000];
int n;
int m;
vector<pair<pair<int,int>,int> > ques;
int ans[500000];
int main() {
    scanf("%d",&n);
    int a;
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        d[i]={a,i};
    }
    sort(d,d+n);
    scanf("%d",&m);
    int k,p;
    for(int i=0;i<m;i++) {
        scanf("%d %d",&k,&p);
        ques.push_back({{k,p},i});
    }
    sort(ques.begin(),ques.end());
    int l=0;
    for(int i=0;i<ques.size();i++) {
        while(l<ques[i].first.first) {
            insert(0,0,n-1,d[l].v,d[l].ind);
            l++;
        }
        ans[ques[i].second]=kth(0,0,n-1,ques[i].first.second);
    }
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}