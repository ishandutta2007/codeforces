#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100002;
struct Uzi{
    int col,sz;
    bool operator<(const Uzi &k)const{
        return sz<k.sz;
    }
}x,y,z;
priority_queue<Uzi>Q;
vector<int>v[N];
int n,A,B,a,b,c,vis[N],cnt[N],Ans[N],i,j,k,o,aa,bb,cc,T;
int Orz[N];
void init(){
    scanf("%d%d%d",&n,&A,&B);
    a=A;b=B-A;c=n-B;
    for(i=1;i<=n+1;i++){
        vis[i]=cnt[i]=0;
        v[i].clear();
    }
    while(Q.size())
    Q.pop();
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        Orz[i]=k;
        vis[k]=1;
        cnt[k]++;
        v[k].push_back(i);
    }
    for(i=1;i<=n+1;i++)
        if(!vis[i])
            o=i;
        else
            Q.push((Uzi){i,cnt[i]});
}
void work(){
    if(b%2&&c&&Q.size()>=2){
        x=Q.top();Q.pop();
        y=Q.top();Q.pop();
        aa=v[x.col].back();v[x.col].pop_back();
        bb=v[y.col].back();v[y.col].pop_back();
        Ans[aa]=o;
        Ans[bb]=x.col;
        b--;
        c--;
        if(--x.sz)Q.push(x);
        if(--y.sz)Q.push(y);
    }
    while(c){
        x=Q.top();Q.pop();
        aa=v[x.col].back();v[x.col].pop_back();
        Ans[aa]=o;
        c--;
        if(--x.sz)Q.push(x);
    }
    if(b%2&&b>=3&&Q.size()>=3){
        x=Q.top();Q.pop();
        y=Q.top();Q.pop();
        z=Q.top();Q.pop();
        aa=v[x.col].back();v[x.col].pop_back();
        bb=v[y.col].back();v[y.col].pop_back();
        cc=v[z.col].back();v[z.col].pop_back();
        Ans[aa]=y.col;
        Ans[bb]=z.col;
        Ans[cc]=x.col;
        b-=3;
        if(--x.sz)Q.push(x);
        if(--y.sz)Q.push(y);
        if(--z.sz)Q.push(z);
    }
    while(b>=2&&Q.size()>=2){
        x=Q.top();Q.pop();
        y=Q.top();Q.pop();
        aa=v[x.col].back();v[x.col].pop_back();
        bb=v[y.col].back();v[y.col].pop_back();
        Ans[aa]=y.col;
        Ans[bb]=x.col;
        b-=2;
        if(--x.sz)Q.push(x);
        if(--y.sz)Q.push(y);       
    }
    if(b){
        printf("NO\n");
        return;
    }
    for(i=1;i<=n+1;i++)
        while(v[i].size()){
            a=v[i].back();
            v[i].pop_back();
            Ans[a]=i;
        }
    printf("YES\n");
    for(i=1;i<=n;i++)
        printf("%d ",Ans[i]);
    printf("\n");
}
int main(){
    scanf("%d",&T);
    while(T--){
        init();
        work();
    }
    return 0;
}