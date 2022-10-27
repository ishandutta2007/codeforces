#include<bits/stdc++.h>
using namespace std;
int n,k,t,x;
map<long long,int> b;
long long g[41];
int dfs(long long mask){
    if(b.count(mask))return b[mask];
    int p=__builtin_ctzll(mask);
    return b[mask]=max(dfs(mask^(1LL<<p)),dfs(mask&g[p])+1);
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&t);
            if(t)g[i]|=(1LL<<j);
        }
    }
    b[0]=0;
    int x=dfs((1LL<<n)-1);
    double ans;
    ans=((double)(k*k)*(double)(x-1)/(double)(2*x));
    printf("%f",(ans));
}