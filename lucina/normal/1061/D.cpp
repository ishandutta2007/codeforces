#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int n,m,y,x;
long long u;
struct pa{
int l;
int r;
bool operator <(const pa x)const{
    if(l!=x.l)
    return l<x.l;
    else
    return r<x.r;
}
}f[maxn];
priority_queue<int> q;
stack<int> p;

int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&f[i].l,&f[i].r);
    }
    sort(f+1,f+1+n);
    long long ans=0;
    long long v=0;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&-q.top()<f[i].l){
            p.push(-q.top());
            q.pop();
        }
        if((p.empty()||(1ll*(f[i].l-p.top())*y)>x)){
            u=1ll*y*(f[i].r-f[i].l);
            ans+=(u+x);
            ans%=mod;
            q.push(-f[i].r);
        }
        else{
            u=1ll*y*(f[i].r-p.top());
            ans+=(u);
            ans%=mod;
            q.push(-f[i].r);
            p.pop();
        }
    }
    printf("%lld\n",ans);
}