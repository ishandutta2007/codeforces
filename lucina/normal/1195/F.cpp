#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int bit[maxn];
int get(int idx){
    int sum=0;
    for(;idx>0;idx-=idx&-idx)
        sum+=bit[idx];
    return sum;
}
int get(int l,int r){
    return get(r)-get(l-1);
}
void upd(int idx,bool Magic){
    for(;idx<maxn;idx+=idx&-idx)
        Magic?bit[idx]++:bit[idx]--;
}
using ve=pair<int,int>;
///Slope of vector
ve make_ve(int x,int y){
    int g=abs(__gcd(x,y));
    x/=g;y/=g;
    return {x,y};
}
void read(ve &x){
    scanf("%d%d",&x.first,&x.second);
}
ve make_ve(ve x, ve y){
    int X=x.first-y.first;
    int Y=x.second-y.second;
    if(Y==0) return {X/abs(X),Y};
    return make_ve(X,Y);
}
struct query{
    int l,r,id;
    void read(int _id){
        scanf("%d%d",&l,&r);
        id=_id;
    }
    bool operator < (const query &x){
        return r<x.r;
    }
};
int ans[100005],m,n;
int l[100005],r[100005];
vector<query> q;
ve a[maxn];
vector<ve> all;
int s[maxn];

int main(){
    scanf("%d",&n);
    int k=1;
    ve fi,nw,lst;
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        read(fi);
        lst=fi;
        for(int j=2;j<=m;j++){
            read(nw);
            a[k+j-1]=make_ve(nw,lst);
            lst=nw;
            all.push_back(a[k+j-1]);
        }
        a[k]=make_ve(fi,lst);
        all.push_back(a[k]);
        l[i]=k,r[i]=k+m-1;
        k+=m;
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    scanf("%d",&m);
    q.resize(m);
    for(int i=1;i<=m;i++){
        q[i-1].read(i);
    }
    sort(q.begin(),q.end());
    int last=0,rr,id;
    for(auto i:q){
        rr=r[i.r];
        if(rr>last){
            for(int j=last+1;j<=rr;j++){
                id=(int)(lower_bound(all.begin(),all.end(),a[j])-all.begin())+1;
                if(s[id]>0){
                    upd(s[id],false);
                    s[id]=j;
                    upd(j,true);
                }
                else{
                    s[id]=j;
                    upd(j,true);
                }
            }
            last=rr;
        }
        ans[i.id]=get(l[i.l],rr);
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
}