#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int mst[maxn];
bool sm[maxn];
int val[maxn][2];
vector<pair<int,bool> > a[maxn];
int n;
int cc;
vector<int> comp[maxn];
int croot[maxn];
int cn[maxn];
char s[maxn];
int k;
vector<int> st[maxn];
vector<int> ins[maxn];
int fnd(int r) {
    if(mst[r]==-1) return min(val[r][0],val[r][1]);
    else return val[r][mst[r]];
}
int force(int t,int v) {
    int r=croot[cn[t]];
    if(mst[r]==-1) {
        int pr=min(val[r][0],val[r][1]);
        if(sm[t]) mst[r]=v;
        else mst[r]=1-v;
        return val[r][mst[r]]-pr;
    }
    else return 0;
}
int traverse(int t,int p=-1) {
    int c=0;
    if(sm[t]) c++;
    for(int i=0;i<a[t].size();i++) {
        int v=a[t][i].first;
        int d=a[t][i].second;
        if(p!=v) {
            sm[v]=sm[t]^d;
            c+=traverse(v,t);
        }
    }
    return c;
}
int force_dif(int t1,int t2,int v) {
    int c1=cn[t1];
    int c2=cn[t2];
    if(c1==c2) return 0;
    int r1=croot[c1];
    int r2=croot[c2];
    int pv=fnd(r1)+fnd(r2);
    //cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<" "<<comp[c1].size()<<" "<<comp[c2].size()<<endl;
    if(comp[c1].size()<comp[c2].size()) {
        int c=comp[c1].size();
        for(int i=0;i<comp[c1].size();i++) {
            int d=comp[c1][i];
            cn[d]=c2;
            comp[c2].push_back(d);
        }
        comp[c1].clear();
        sm[t1]=sm[t2]^v;
        int t=traverse(t1);
        a[t1].push_back({t2,v});
        a[t2].push_back({t1,v});
        val[r2][1]+=t;
        val[r2][0]+=(c-t);
        if(mst[r1]!=-1) {
            mst[r2]=mst[r1]^(1-sm[r1]);
        }
        return fnd(r2)-pv;
    }
    else {
        int c=comp[c2].size();
        for(int i=0;i<comp[c2].size();i++) {
            int d=comp[c2][i];
            cn[d]=c1;
            comp[c1].push_back(d);
        }
        comp[c2].clear();
        sm[t2]=sm[t1]^v;
        int t=traverse(t2);
        a[t1].push_back({t2,v});
        a[t2].push_back({t1,v});
        //cout<<c<<" "<<t<<endl;
        val[r1][1]+=t;
        val[r1][0]+=(c-t);
        //cout<<val[r1][1]<<" "<<val[r1][0]<<endl;
        if(mst[r2]!=-1) {
            mst[r1]=mst[r2]^(1-sm[r2]);
        }
        //cout<<mst[r1]<<" "<<fnd(r1)<<" "<<pv<<endl;
        return fnd(r1)-pv;
    }
}
int main() {
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    cc=maxn;
    for(int i=1;i<=k;i++) {
        comp[i].push_back(i);
        val[i][0]=0;
        val[i][1]=1;
        croot[i]=i;
        cn[i]=i;
        sm[i]=true;
        mst[i]=-1;
    }
    for(int i=1;i<=k;i++) {
        int l,t;
        scanf("%d",&l);
        for(int j=0;j<l;j++) {
            scanf("%d",&t);
            st[i].push_back(t);
            ins[t].push_back(i);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(ins[i].size()!=0) {
            if(ins[i].size()==1) {
                int t=ins[i][0];
                if(s[i-1]=='0') ans+=force(t,1);
                else ans+=force(t,0);
            }
            else {
                int t1=ins[i][0];
                int t2=ins[i][1];
                if(s[i-1]=='0') ans+=force_dif(t1,t2,1);
                else ans+=force_dif(t1,t2,0);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}