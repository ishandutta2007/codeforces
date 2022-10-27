#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct BIT{
long long bit[1000010];
long long get(int idx){
    long long sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,long long val){
    while(idx<=1000001){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return ;
}
int lifting(long long val){
    int pos=0;long long sum=0;
    for(int j=21;j>=0;j--){
        if((pos+(1<<j)<=1000000)&&(sum+bit[pos+(1<<j)]<=val)){
            sum+=bit[pos+(1<<j)];
            pos+=(1<<j);
        }
    }
    return pos+1;
}
}f1,f2;
int n,x[maxn],t[maxn],u,v;
long long T;
vector<pair<int,int>> a[maxn];
long long dfs(int nod,long long X){
    f1.update(t[nod],x[nod]);
    f2.update(t[nod],1ll*x[nod]*t[nod]);
    long long cur=T-2*X;
    int g=f2.lifting(cur);
    long long b=f1.get(g-1);
    long long c=f2.get(g-1);
    long long ma=f1.get(g)-f1.get(g-1);
    b+=min((cur-c)/g,ma);
    long long m1=0,m2=0;
    for(auto i:a[nod]){
            long long d=dfs(i.first,X+i.second);
            if(d>=m1){
                m2=m1;m1=d;
            }
            else if(m2<d){
                m2=d;
            }
        }
    f1.update(t[nod],-x[nod]);
    f2.update(t[nod],-1ll*x[nod]*t[nod]);
    if(nod==1)return max(m1,b);
    else return max(m2,b);
}

int main(){
    scanf("%d%lld",&n,&T);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=2;i<=n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(make_pair(i,v));
    }
    printf("%lld\n",dfs(1,0));
}