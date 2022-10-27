#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct pt{
    int x,y;
    friend int dist(pt a,pt b){
        return abs(a.x-b.x)+abs(a.y-b.y);
    }
    bool operator<(const pt &a)const{
        return x==a.x?y<a.y:x<a.x;
    }
    friend bool operator ==(const pt &a,const pt &b){
        return a.x==b.x&&a.y==b.y;
    }
    friend bool operator !=(const pt &a,const pt &b){
        return !(a==b);
    }
}p[maxn];
bool cmp(const pt &a, const pt &b){
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
int n,mx,my,mix,miy;
long long sum,ans;
vector<pt> f;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        if(i>1) sum+=dist(p[i],p[i-1]);
    }
    sum+=dist(p[1],p[n]);
    if(n==3)return !printf("%lld\n",sum);
    set<pt> s;
    sort(p+1,p+1+n);
    s.insert(p[1]);
    for(int i=1;i<=n;i++){
        if(p[i].x==p[1].x);
        else {
            s.insert(p[i-1]);
            break;
        }
    }
    s.insert(p[n]);
    for(int i=n;i>=1;i--){
        if(p[i].x==p[n].x);
        else {
        s.insert(p[i+1]);
        break;
        }
    }
    sort(p+1,p+1+n,cmp);
    s.insert(p[1]);
    for(int i=1;i<=n;i++){
        if(p[i].y==p[1].y);
        else {
        s.insert(p[i-1]);
        break;
        }
    }
    s.insert(p[n]);
    for(int i=n;i>=1;i--){
        if(p[i].y==p[n].y);
        else {
        s.insert(p[i+1]);
        break;
        }
    }
    for(auto i:s){
        f.push_back(i);
    }
    for(int i=0;i<f.size();i++){
        for(int j=i+1;j<f.size();j++){
            for(int k=1;k<=n;k++){
                if(p[k]!=f[i]&&p[k]!=f[j]){
                    ans=max(ans,0ll+dist(f[i],f[j])+dist(f[i],p[k])+dist(f[j],p[k]));
                }
            }
        }
    }
    printf("%lld ",ans);
    for(int i=4;i<=n;i++)
        printf("%lld ",sum);
}