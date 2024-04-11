#include<bits/stdc++.h>
#define maxn 600000
#define lg 20
using namespace std;
int n,d;
pair<pair<int,int>,pair<int,int> > x[maxn];
int s[maxn];
int a[maxn];
int impl[lg*maxn];
int laz[lg*maxn];
int l[lg*maxn];
int r[lg*maxn];
int cid=2;
void propagate(int id,int x,int y) {
    impl[id]+=laz[id];
    if(x!=y) {
        if(l[id]==0) l[id]=cid++;
        if(r[id]==0) r[id]=cid++;
        laz[l[id]]+=laz[id];
        laz[r[id]]+=laz[id];
    }
    laz[id]=0;
}
int getmax(int id,int x,int y,int p) {
    propagate(id,x,y);
    if(id==0 || x>p) return 0;
    if(y<=p) return impl[id];
    int z=(x+y)/2;
    return max(getmax(l[id],x,z,p),getmax(r[id],z+1,y,p));
}
void setmax(int id,int x,int y,int p,int v) {
    //assert(id!=0);
    propagate(id,x,y);
    impl[id]=max(impl[id],v);
    if(x==y) return;
    int z=(x+y)/2;
    if(p<=z) {
        if(l[id]==0) l[id]=cid++;
        setmax(l[id],x,z,p,v);
    }
    else {
        if(r[id]==0) r[id]=cid++;
        setmax(r[id],z+1,y,p,v);
    }
    impl[id]=max(impl[id],max(impl[l[id]],impl[r[id]]));
}
void updatemax(int id,int x,int y,int p,int q) {
    if(id==0) return;
    //assert(id!=0);
    propagate(id,x,y);
    if(q<x || y<p) return;
    if(p<=x && y<=q) {
        laz[id]+=1;
        propagate(id,x,y);
        return;
    }
    int z=(x+y)/2;
    //if(l[id]==0) l[id]=cid++;
    //if(r[id]==0) r[id]=cid++;
    updatemax(l[id],x,z,p,q);
    updatemax(r[id],z+1,y,p,q);
    impl[id]=max(impl[id],max(impl[l[id]],impl[r[id]]));
}
vector<int> pom;
map<int,int> m;
int main() {
    scanf("%d %d",&n,&d);
    pom.push_back(d);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&s[i],&a[i]);
        pom.push_back(s[i]);
        pom.push_back(a[i]);
    }
    sort(pom.begin(),pom.end());
    int ml=0;
    for(int i=0;i<pom.size();i++) {
        if(i==0 || pom[i]!=pom[i-1]) {
            m[pom[i]]=ml;
            ml++;
        }
    }
    d=m[d];
    for(int i=0;i<n;i++) {
        s[i]=m[s[i]];
        a[i]=m[a[i]];
        x[i]={{max(s[i],a[i]),min(s[i],a[i])},{s[i],a[i]}};
    }
    sort(x,x+n);
    int ans=0;
    for(int i=0;i<n;i++) {
        int s=x[i].second.first;
        int a=x[i].second.second;
        if(s<d) continue;
        int cans=1+getmax(1,0,ml,s);
        //cout<<s<<" "<<a<<endl;
        //cout<<cans<<endl;
        ans=max(ans,cans);
        if(a<s) {
            int tans=1+getmax(1,0,ml,a);
            setmax(1,0,ml,a,tans);
            //cout<<getmax(1,0,1e9,s)<<endl;
            updatemax(1,0,ml,a+1,s);
            //cout<<getmax(1,0,1e9,s)<<endl;
        }
        else setmax(1,0,ml,a,cans);
    }
    printf("%d",ans);
    return 0;
}